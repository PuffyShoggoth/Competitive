n, k=map(int, input().split())
import sys
d=[0]*n
ps=[0]*n
sm=0
for i in range(1, n+1):
   ck=int(sys.stdin.readline())
   d[ck-1]=i
sm+=d[0]-1
if d[n-1]>d[0]: ps[0]=n-d[n-1]+d[0]
else: ps[0]=d[0]-d[n-1]
for i in range(1, n):
   if d[i]>d[i-1]: ps[i]=ps[i-1]+d[i]-d[i-1]
   else: ps[i]=ps[i-1]+n-d[i-1]+d[i]
sm+=(k//n)*ps[n-1]
sm-=ps[0]
if k%n!=0: sm+=ps[k%n-1]
print(sm)