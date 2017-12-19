import math
def pfact(x):
   l=[]
   for i in range(2, int(math.sqrt(x))+2):
      while x%i==0:
         l.append(i)
         x=x//i
   if x!=1: l.append(x)
   l.reverse()
   return l
def mc(l):
   sm=0
   while len(l)>1:
      k=l.pop()
      if k==2: sm+=1
      else: sm+=mc(pfact(k-1))+k-1
   if l[0]==2: return sm+1
   else: 
      sm+=mc(pfact(l[0]-1))+l[0]-1
   return sm
banananaa=int(input())
if banananaa==1: print(0)
else: print(mc(pfact(banananaa)))