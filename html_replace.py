import json
with open("info.json") as F:
	dic = json.load(F)

files_dir = ['.', 'research','tutoring','past_teaching', 'publications', 'research/gradient-flow', 'research/mean-field-games']

print("XXX Processing XXX")
for file_dir in files_dir:
	print(file_dir)
	html = ""
	with open("{}/body.txt".format(file_dir)) as F:
		for i in F:
			if('<%' in i):
				key = i.split('%')[1]
				html += dic[key]
			else:
				html += i

	with open("{}/index.html".format(file_dir),"w") as F:
		F.write(html)
print("XXX Done! XXX")