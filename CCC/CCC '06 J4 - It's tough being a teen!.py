cd=[[],[7, 4], [1], [4, 5], [], [], [], []]
f=[[],[2], [], [], [1, 3], [3], [], [1]]
j=int(input())
k=int(input())
while j!=0 and k!=0:
   cd[j].append(k)
   f[k].append(j)
   j=int(input())
   k=int(input())
c=1
p=False
d=[]
while c<9:
   if c==8: break
   for i in range(1, 9):
      if i==8: 
         p=True
         break
      elif f[i]!=[-1]: break
   if p: break
   if len(f[c])==0:
         d.append(c)
         f[c]=[-1]
         for k in cd[c]:
                 f[k].remove(c)
         c=0
   c+=1
if c==8: print("Cannot complete these tasks. Going to bed.")
else:
   for i in d:
         print(i, end=" ")