import argparse
import os
import numpy as np
import math
import sys
import matplotlib.pyplot as plt

import torchvision.transforms as transforms
from torchvision.utils import save_image

from torch.utils.data import DataLoader
from torchvision import datasets
from torch.autograd import Variable

import torch.nn as nn
import torch.nn.functional as F
import torch.autograd as autograd
import torch

os.makedirs("images", exist_ok=True)

parser = argparse.ArgumentParser()
parser.add_argument("--n_epochs", type=int, default=200, help="number of epochs of training")
parser.add_argument("--batch_size", type=int, default=256, help="size of the batches")
parser.add_argument("--lr", type=float, default=0.0001, help="adam: learning rate")
parser.add_argument("--b1", type=float, default=0.5, help="adam: decay of first order momentum of gradient")
parser.add_argument("--b2", type=float, default=0.999, help="adam: decay of first order momentum of gradient")
parser.add_argument("--n_cpu", type=int, default=8, help="number of cpu threads to use during batch generation")
parser.add_argument("--latent_dim", type=int, default=100, help="dimensionality of the latent space")
parser.add_argument("--img_size", type=int, default=28, help="size of each image dimension")
parser.add_argument("--channels", type=int, default=1, help="number of image channels")
parser.add_argument("--n_critic", type=int, default=5, help="number of training steps for disc_psi per iter")
parser.add_argument("--clip_value", type=float, default=0.01, help="lower and upper clip value for disc. weights")
parser.add_argument("--sample_interval", type=int, default=200, help="interval betwen image samples")
opt = parser.parse_args()
print(opt)

img_shape = (opt.channels, opt.img_size, opt.img_size)

cuda = True if torch.cuda.is_available() else False


# Loss weight for gradient penalty
DIM_SUBSPACE = opt.latent_dim
epsilon   = 0.5
lambda_TS = 5
sigma = 0.1



""" from N(0,1) to Y space """
class Generator(nn.Module):
    def __init__(self):
        super(Generator, self).__init__()

        def block(in_feat, out_feat, normalize=True):
            layers = [nn.Linear(in_feat, out_feat)]
            if normalize:
                layers.append(nn.BatchNorm1d(out_feat, 0.8))
            layers.append(nn.LeakyReLU(0.2, inplace=True))
            return layers

        self.model = nn.Sequential(
            nn.Linear(int(np.prod(opt.latent_dim)), 512),
            nn.LeakyReLU(0.2, inplace=True),
            nn.Linear(512, 512),
            nn.LeakyReLU(0.2, inplace=True),
            nn.Linear(512, DIM_SUBSPACE),
        )

    def forward(self, z):
        img = self.model(z)
        return img

""" from mu to Y space """
class GeneratorT(nn.Module):
    def __init__(self):
        super(GeneratorT, self).__init__()

        self.model = nn.Sequential(
            nn.Linear(int(np.prod(img_shape)), 512),
            nn.LeakyReLU(0.2, inplace=True),
            nn.Linear(512, 256),
            nn.LeakyReLU(0.2, inplace=True),
            nn.Linear(256, DIM_SUBSPACE),
        )

    def forward(self, img):
        img_flat = img.view(img.shape[0], -1)
        validity = self.model(img_flat)
        return validity

""" from Y space to mu """
class GeneratorS(nn.Module):
    def __init__(self):
        super(GeneratorS, self).__init__()

        def block(in_feat, out_feat, normalize=True):
            layers = [nn.Linear(in_feat, out_feat)]
            if normalize:
                layers.append(nn.BatchNorm1d(out_feat, 0.8))
            layers.append(nn.LeakyReLU(0.2, inplace=True))
            return layers

        self.model = nn.Sequential(
            *block(DIM_SUBSPACE, 128, normalize=False),
            *block(128, 256),
            *block(256, 512),
            *block(512, 1024),
            nn.Linear(1024, int(np.prod(img_shape))),
            nn.Tanh()
        )

    def forward(self, z):
        img = self.model(z)
        img = img.view(img.shape[0], *img_shape)
        return img

""" phi and psi functions """
class Discriminator(nn.Module):
    def __init__(self):
        super(Discriminator, self).__init__()

        self.model = nn.Sequential(
            nn.Linear(DIM_SUBSPACE, 512),
            nn.LeakyReLU(0.2, inplace=True),
            nn.Linear(512, 256),
            nn.LeakyReLU(0.2, inplace=True),
            nn.Linear(256, 1),
        )

    def forward(self, img):
        img_flat = img.view(img.shape[0], -1)
        validity = self.model(img_flat)
        return validity


# Initialize generator and disc_psi
genG       = Generator()          # G
genT       = GeneratorT()         # T
genS       = GeneratorS()         # S
disc_psi   = Discriminator() # real psi
disc_phi   = Discriminator() # fake phi

if cuda:
    genG.cuda()
    genT.cuda()
    disc_psi.cuda()
    disc_phi.cuda()

# Configure data loader
os.makedirs("../../data/mnist", exist_ok=True)
dataloader = torch.utils.data.DataLoader(
    datasets.MNIST(
        "../../data/mnist",
        train=True,
        download=True,
        transform=transforms.Compose(
            [transforms.Resize(opt.img_size), transforms.ToTensor(), transforms.Normalize([0.5], [0.5])]
        ),
    ),
    batch_size=opt.batch_size,
    shuffle=True,
)

# Optimizers
optimizer_G  = torch.optim.Adam(genG.parameters(),      lr=opt.lr, betas=(opt.b1, opt.b2))
optimizer_T  = torch.optim.Adam(genT.parameters(),     lr=opt.lr, betas=(opt.b1, opt.b2))
optimizer_S  = torch.optim.Adam(genS.parameters(),     lr=opt.lr, betas=(opt.b1, opt.b2))
optimizer_D  = torch.optim.Adam(disc_psi.parameters(),  lr=opt.lr, betas=(opt.b1, opt.b2))
optimizer_D2 = torch.optim.Adam(disc_phi.parameters(), lr=opt.lr, betas=(opt.b1, opt.b2))

Tensor = torch.cuda.FloatTensor if cuda else torch.FloatTensor

def compute_entropic_regularizer_penalty(D, D2, T, real_samples, fake_samples, epsilon):
    """Calculates the enropic regualizer penalty loss for W2GAN """
    # Random weight term for interpolation between real and fake samples

    # total number of images from real and fake samples
    real_samples = T(real_samples) # from mu to Y space

    l_real = len(real_samples)
    l_fake = len(fake_samples)

    # dimesion of real = (N, 1, 28, 28)
    d_real = real_samples.size(1)
    d_fake = fake_samples.size(1)

    # tmp_c is a cost matrix (cost = |x-y|^2/2)
    tmp_c = torch.mean((real_samples.view((l_real, 1, d_real)) - fake_samples.view((1, l_fake, d_fake)))**2, dim=2)
    Dval  = D(real_samples)
    D2val = D2(fake_samples)

    return torch.mean(torch.exp(-(tmp_c - Dval.view((l_real, 1)) - D2val.view((1, l_fake))) / epsilon))

def compute_identity_penalty(T, S, real_samples, fake_samples):
    """Calculates the identity penalty loss. S(T(x)) = x """
    return torch.mean((S(T(real_samples)) - real_samples) **2) + torch.mean((T(S(fake_samples)) - fake_samples) **2)
    # return torch.mean(torch.abs(S(T(real_samples)) - real_samples)) + torch.mean(torch.abs(T(S(fake_samples)) - fake_samples))
    

def compute_gradient_penalty(D, real_samples, fake_samples):
    """Calculates the gradient penalty loss for WGAN GP"""
    # Random weight term for interpolation between real and fake samples
    alpha = Tensor(np.random.random((real_samples.size(0), 1, 1, 1)))
    # Get random interpolation between real and fake samples
    interpolates = (alpha * real_samples + ((1 - alpha) * fake_samples)).requires_grad_(True)
    d_interpolates = D(interpolates)
    fake = Variable(Tensor(real_samples.shape[0], 1).fill_(1.0), requires_grad=False)
    # Get gradient w.r.t. interpolates
    gradients = autograd.grad(
        outputs=d_interpolates,
        inputs=interpolates,
        grad_outputs=fake,
        create_graph=True,
        retain_graph=True,
        only_inputs=True,
    )[0]
    gradients = gradients.view(gradients.size(0), -1)
    gradient_penalty = (gradients.norm(2, dim=1) ** 2).mean()
    return gradient_penalty

def compute_proximal_penalty(real_validity, fake_validity):
    real_validity_clone = torch.clone(real_validity).detach()
    fake_validity_clone = torch.clone(fake_validity).detach()
    return torch.mean((real_validity - real_validity_clone) ** 2) + torch.mean((fake_validity - fake_validity_clone) ** 2)


def compute_primal_proximal_penalty(genG, genT, genS, real_imgs, fake_imgs):
    genG_clone = torch.clone(fake_imgs).detach()
    genT_clone = torch.clone(genT(real_imgs)).detach()
    genS_clone = torch.clone(genS(fake_imgs)).detach()
    return torch.mean((fake_imgs - genG_clone) ** 2) + torch.mean((genT(real_imgs) - genT_clone) ** 2) + torch.mean((genS(fake_imgs) - genS_clone) ** 2)

# ----------
#  Training
# ----------

batches_done = 0
for epoch in range(opt.n_epochs):
    for i, (imgs, _) in enumerate(dataloader):

        # Configure input
        real_imgs = Variable(imgs.type(Tensor))

        # ---------------------
        #  Train Discriminator
        # ---------------------

        optimizer_D.zero_grad()
        optimizer_D2.zero_grad()

        # Sample noise as genG input
        z = Variable(Tensor(np.random.normal(0, 1, (imgs.shape[0], opt.latent_dim))))

        # Generate a batch of images
        fake_imgs = genG(z)

        # print(real_imgs.shape, fake_imgs.shape)

        # Real images
        real_validity = disc_psi(genT(real_imgs))
        # Fake images
        fake_validity = disc_phi(fake_imgs)
        # Entropic Regularizer
        entropic_penalty = compute_entropic_regularizer_penalty(disc_psi, disc_phi, genT, real_imgs.data, fake_imgs, epsilon)

        # proximal regularizer
        proximal_penalty = compute_proximal_penalty(real_validity, fake_validity)

        # Adversarial loss
        d_loss = - torch.mean(real_validity) - torch.mean(fake_validity) + epsilon * entropic_penalty - sigma * proximal_penalty

        d_loss.backward()
        optimizer_D.step()
        optimizer_D2.step()



        # Train the genG every n_critic steps
        if i % opt.n_critic == 0:
            # -----------------
            #  Train Generator
            # -----------------

            optimizer_G.zero_grad()
            optimizer_T.zero_grad()
            optimizer_S.zero_grad()

            real_imgs = Variable(imgs.type(Tensor))
            real_validity = disc_psi(genT(real_imgs))

            z = Variable(Tensor(np.random.normal(0, 1, (imgs.shape[0], opt.latent_dim))))
            # Generate a batch of images
            fake_imgs = genG(z)
            # Loss measures genG's ability to fool the disc_psi
            # Train on fake images
            fake_validity = disc_phi(fake_imgs)

            # Entropic Regularizer
            entropic_penalty = compute_entropic_regularizer_penalty(disc_psi, disc_phi, genT, real_imgs.data, fake_imgs, epsilon)

            # identity regularizer for T(S(x)) = x
            identity_penalty = compute_identity_penalty(genT, genS, real_imgs.data, fake_imgs.data)

            primal_proximal_penalty = compute_primal_proximal_penalty(genG, genT, genS, real_imgs.data, fake_imgs.data)


            g_loss = torch.mean(real_validity) + torch.mean(fake_validity)  - epsilon * entropic_penalty + lambda_TS * identity_penalty + sigma * primal_proximal_penalty


            g_loss.backward()
            optimizer_G.step()
            optimizer_T.step()
            optimizer_S.step()

            print(
                "[Epoch %d/%d] [Batch %d/%d] [D loss: %f] [G loss: %f]"
                % (epoch, opt.n_epochs, i, len(dataloader), d_loss.item(), g_loss.item())
            )

            if batches_done % opt.sample_interval == 0:
                fake_imgs_from_gen = genS(genG(z))
                save_image(fake_imgs_from_gen.data[:25], "images/%d.png" % int(batches_done/opt.sample_interval), nrow=5, normalize=True)

            batches_done += opt.n_critic