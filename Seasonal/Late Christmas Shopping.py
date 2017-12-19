gifts=int(input())
l=[]
k=False
for banana in range(0, gifts):
   thisg=input().split()
   papaya=int(thisg[0])
   for i in thisg[1:len(thisg)]:
      while thisg[1:len(thisg)].count(i)>1:
         thisg.remove(i)
   for i in thisg[1:len(thisg)]:
      if i in l: k=True
      l.append(i)
if k: print("YES")
else: print("NO")