nn=int(input())
d={}
import math
from collections import defaultdict
mn=defaultdict(int)
def nut(n, q):
   if n==1: 
      mn[1]=max(mn[1], q)
      return
   if q<=mn[n]: return
   mn[n]=q
   if d[n][2]==1: nut(d[n][0], math.sqrt(q)/(d[n][1]/100))
   else: nut(d[n][0], q/(d[n][1]/100))
   return
for i in range(nn-1):
   l=[int(x) for x in input().split()]
   d[l[1]]=tuple([l[0], l[2], l[3]])
nl=[int(x) for x in input().split()]
for i in range(0, nn):
   if nl[i]!=-1:
      nut(i+1, nl[i])
print("%.3f"% round(mn[1], 3))