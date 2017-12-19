p=bool(input()=="trees!")#I missed python... 
scores=[0, 0, 0, 0]#Happy New Year!
sections=[0, 0, 0, 0]
for i in range(0, 4):
   q=[float(x) for x in input().split()]
   sections[i]=q[2]
   scores[i]=q[0]/q[1]
if p:
   scores[sections.index(max(sections))]=1
else:
   scores[sections.index(max(sections))]=0
tot=0
for i in range(0, 4):
   tot+=round(scores[i]*sections[i]*100)
print(tot)