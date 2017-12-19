import sys
from collections import defaultdict
f=defaultdict(int)
n=int(input())
for x in sys.stdin.read().split():
   f[int(x)]+=1
maxman=0
spaace=max(f)//2
for i in range(0, n):
   if not f: break
   p=max(f)
   if p*3<=maxman: break
   if f[p]==3: 
      maxman=max(maxman, p*3)
      del f[p]
      continue
   for k in range(1, min(p//2+1, spaace)):
      if p-k in f and p-k*2 in f:
         maxman=max(maxman, (p-k)*3)
         spaace=k
         break
   del f[p]
print(maxman)