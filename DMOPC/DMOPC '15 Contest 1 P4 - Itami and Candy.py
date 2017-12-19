n, x=map(int, input().split())
s=[0 for i in range(n+10)]
s[0]=1
s[1]=1
ttl=0
import math
for i in range(int(math.sqrt(n))+1):
   if s[i]==1: continue
   for k in range(i*i, n+1, i): s[k]=1
for i in range(n):
   if s[i]==0: 
      ttl+=((n-i)//x)*2+2
      if (n-i)%x==0: ttl-=1
if s[n]==0: ttl+=1
print(ttl)