# Update head and body in each week

### setup the parameters
# how many weeks?
weeks = 10


# DON'T TOUCH BELOW 
folders = ["home"]
for i in range(weeks):
  folders.append("week{}".format(i+1))
folders.append("final")
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
  body = ""
  with open("{}/body.html".format(folder), "r") as F:
    for i in F:
      body += i

  

  body = head + body + tail

  with open("{}/index.html".format(folder), "w") as f:
    f.write(body)