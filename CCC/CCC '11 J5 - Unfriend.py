from collections import defaultdict
h=int(input())
p=defaultdict(list)
l=[]
for i in range(1, h):
   q=int(input())
   p[q].append(i)
   l.append(i)
l.append(h)
def fac(x):
   if x==0: return 1
   else: return x*fac(x-1)
def combos(x, t):
   if t==0: return 1
   sumn= fac(x)//(fac(x-t)*fac(t))
   return sumn+combos(x, t-1)

def go(x):
   if x in p:
      po=1
      l=0
      for i in range(0, len(p[x])):
        if p[x][i] in p: 
            po=po*(go(p[x][i])+1)
            l=l+1
      return combos(len(p[x])-l, len(p[x])-l)*po
   return 2
if h!=1: print(go(h))
else: print(0)