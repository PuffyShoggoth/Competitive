t=int(input())
import sys
a=''
b=''
an=0
bn=0
for i in range(0, t):
   k=sys.stdin.readline().split()
   tn=int(k[1])*2+int(k[2])*3+int(k[3])
   if tn<bn: continue
   elif tn==an and an==bn: 
      if k[0]<a: a, b=k[0], a
      else: b=min(k[0], b)
      continue
   elif tn==an:
      a, b=min(k[0], a), max(k[0], a)
      continue
   elif tn==bn:
      b=min(k[0], a)
      continue
   elif tn>an:
      an, bn=tn, an
      a, b=k[0], a
      continue
   else:
      bn=tn
      b=k[0]
if a!='': print(a)
if b!='': print(b)