# Update head and body in each week

### setup the parameters
# how many weeks?
weeks = 10




# DON'T TOUCH BELOW 

import json

with open("../../info.json") as F:
  dic = json.load(F)



folders = ["home"]
for i in range(weeks):
  folders.append("week{}".format(i+1))
print(folders)

head = ""
with open("head.html", "r") as F:
  for i in F:
    head += i

tail = """

    <div class="bottom-blank">
    </div>

    </body>

  </html>
"""

for folder in folders:
  print(folder)
  body = ""
  with open("{}/body.txt".format(folder), "r") as F:
    for i in F:
      print(i)
      if '<%' in i:
        key = i.split('%')[1]
        body += dic[key]
      else:
        body += i

  print(body)
  

  body = head + body + tail

  with open("{}/index.html".format(folder), "w") as f:
    f.write(body)