#This sets up Kaggle to download directly to Google Colab (only needs to run once)
!mkdir -p ~/.kaggle
!wget https://www-users.math.umn.edu/~jwcalder/MCFAM/kaggle.json -P ~/.kaggle/
!chmod 600 ~/.kaggle/kaggle.json

#We now download and unzip the Sign Language MNIST dataset from Kaggle
import zipfile

!kaggle datasets download -d datamunge/sign-language-mnist
with zipfile.ZipFile("sign-language-mnist.zip","r") as zip_ref:
    zip_ref.extractall(".")
!ls -l

#Let's load the training data with pandas
import pandas as pd

df_train = pd.read_csv('sign_mnist_train.csv')
df_test = pd.read_csv('sign_mnist_test.csv')

#The first column is the label and the rest are the pixel values
train_labels = df_train.values[:,0]
train_data = df_train.values[:,1:]

test_labels = df_test.values[:,0]
test_data = df_test.values[:,1:]

#Convert to 3 color channels
train_data = np.reshape(train_data,(train_data.shape[0],28,28))
train_data = np.stack((train_data,train_data,train_data),axis=1)

test_data = np.reshape(test_data,(test_data.shape[0],28,28))
test_data = np.stack((test_data,test_data,test_data),axis=1)
print(train_data.shape)
print(train_labels.shape)

#Convert to torch
train_data = torch.from_numpy(train_data).float()
train_target = torch.from_numpy(train_labels).long()

test_data = torch.from_numpy(test_data).float()
test_target = torch.from_numpy(test_labels).long()

import torch
from torchvision import transforms
from torch.utils.data import Dataset, DataLoader
import numpy as np
from PIL import Image


class MyDataset(Dataset):
    def __init__(self, data, targets, transform=None):
        self.data = data
        self.targets = targets
        self.transform = transform

    def __getitem__(self, index):
        x = self.data[index]
        y = self.targets[index]

        if self.transform:
            x = self.transform(x)

        return x, y

    def __len__(self):
        return len(self.data)

#We removed "ToTensor" since we already made the data a torch tensor
data_transforms = {
    'train': transforms.Compose([
        transforms.RandomResizedCrop(224),
        transforms.RandomHorizontalFlip(),
        transforms.Normalize([0.485, 0.456, 0.406], [0.229, 0.224, 0.225])
    ]),
    'val': transforms.Compose([
        transforms.Resize(256),
        transforms.CenterCrop(224),
        transforms.Normalize([0.485, 0.456, 0.406], [0.229, 0.224, 0.225])
    ]),
}

#Then we can construct a dataset and dataloader for train and testing data
train_size = len(train_data)
val_size = len(test_data)
dataset_train = MyDataset(train_data, train_target, transform=data_transforms['train'])
dataloader_train = DataLoader(dataset_train, batch_size=64)

dataset_val = MyDataset(test_data, test_target, transform=data_transforms['val'])
dataloader_val = DataLoader(dataset_val, batch_size=64)

#Put together in python dictionary, like in this notebook
dataloaders = {'train':dataloader_train, 'val':dataloader_val}
dataset_sizes = {'train':train_size, 'val':val_size}
class_names = [str(i) for i in range(25)]

# device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")
device = torch.device('cpu')

model_conv = torchvision.models.resnet18(weights='IMAGENET1K_V1')
for param in model_conv.parameters():
    param.requires_grad = False

#Replace fully connected layer by a new linear layer
#Parameters of newly constructed modules have requires_grad=True by default
num_ftrs = model_conv.fc.in_features
model_conv.fc = nn.Linear(num_ftrs, 25)
model_conv = model_conv.to(device)

#Observe that only parameters of final layer are being optimized as opposed to before.
optimizer_conv = optim.SGD(model_conv.fc.parameters(), lr=0.001, momentum=0.9)

#Train network with cross entropy loss
#Decay LR by a factor of 0.1 every 7 epochs
criterion = nn.CrossEntropyLoss()
exp_lr_scheduler = lr_scheduler.StepLR(optimizer_conv, step_size=7, gamma=0.1)
model_conv = train_model(model_conv, criterion, optimizer_conv, exp_lr_scheduler, num_epochs=5)