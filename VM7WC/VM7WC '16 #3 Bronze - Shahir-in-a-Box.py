import sys
n=int(input())
mx=0
mnx=5000
mny=5000
my=0
for i in range(n):
   x, y = map(int, sys.stdin.readline().split())
   mx=max(x, mx)
   mnx=min(x, mnx)
   my=max(y, my)
   mny=min(y, mny)
print((mx-mnx)*(my-mny))