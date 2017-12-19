n=int(input())
dl={}
glet=[]
for i in range(0, 26):
   dl[chr(ord("a")+i)]=0
for i in range(n):
   name=input()
   dl[name[0]]=dl[name[0]]+1
for j in dl:
   if dl[j]>=5: glet.append(j)
glet.sort()
if len(glet)>0: print("".join(glet))
else: print("PREDAJA")