import requests
import os
import time
def extension(language):
	if language[0:2]=='PY': return '.py'
	elif language[0:4]=='JAVA': return '.java'
	elif language[0]=='C': return '.cpp'
	else:
		print("Language not found: ", language)
		return '.txt'
def toFileName(name):
        d = {'/':'-', '\\':'-', '*':'', '?':'', ':':'-', '<':' ', '>':' ', '"':"'", "|":'-'}
        for i in d:
                name=name.replace(i, d[i])
        return name
def saveProblem(group, name, language, text):
    f = open(group+"\\"+toFileName(name)+extension(language), "w")
    f.write(text)
    f.close()
header = {
    "Cookie":"" #whatever your Cookie header is
    }
def getSubmission(submissionId):
        return requests.get("https://dmoj.ca/src/"+submissionId+"/raw", headers=header).text.replace('\r\n', '\r').replace('\r', '\n')

username = "" #whatever your username is
problemlist = requests.get("https://dmoj.ca/api/user/submissions/"+username).json()
ac = {x:problemlist[x] for x in problemlist if problemlist[x]["result"]=="AC"}
#get all problems so you don't have to make as many api calls
problems = requests.get("https://dmoj.ca/api/problem/list").json()
#filter out anything that didn't get full points
ac = {x:ac[x] for x in ac if ac[x]['points']==problems[ac[x]['problem']]['points']}
#get the fastest submission for each problem
fs = {}
for i in ac:
    if ac[i]['problem'] in fs:
        fs[ac[i]['problem']]=min(fs[ac[i]['problem']], ac[i]['time'])
    else:
        fs[ac[i]['problem']]=ac[i]['time']
best = {x:ac[x] for x in ac if fs[ac[x]['problem']]==ac[x]['time']}
#set up folders for different categories/contests
groups = set(problems[best[x]['problem']]['group'] for x in best)
for name in groups:
    os.makedirs(name, exist_ok=True)
cnt  = 0
for i in best:
        p = problems[best[i]['problem']]
        r = getSubmission(i)
        time.sleep(1)
        saveProblem(p['group'], p['name'], best[i]['language'],r)
        cnt+=1
        if (cnt%10==0): print(cnt)
        
print("done")
