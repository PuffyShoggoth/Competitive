import math
d=int(input())
for i in range(0, d):
   ax, ay, bx, by, cx, cy=map(int, input().split())
   sa=math.sqrt((ax-bx)**2+(ay-by)**2)
   sb=math.sqrt((bx-cx)**2+(by-cy)**2)
   sc=math.sqrt((cx-ax)**2+(cy-ay)**2)
   p=sa+sb+sc
   q=p/2
   a=math.sqrt(q*(q-sa)*(q-sb)*(q-sc))
   if p%0.01>=0.005: p=p//0.01/100+0.01
   else: p=p//0.01/100
   if a%0.01>=0.005: a=a//0.01/100+0.01
   else: a=a//0.01/100
   print(a, p)