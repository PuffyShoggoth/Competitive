h=int(input())
li=input().split()
lk=input().split()
p={}
o=True
for i in range(0, h):
   if  lk[i]==li[i]: 
      o=False
      break
   if li[i] and lk[i] not in p: p[li[i]]=lk[i]
   else: 
      if p[lk[i]]!=li[i]: 
         o=False
         break
if o==True: print("good")
else: print("bad")