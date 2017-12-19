n, k=map(int, input().split())
import sys
l=[]
for i in range(0, n):
   l.append(int(sys.stdin.readline()))
l.sort()
t=0
for i in range(len(l)-1, len(l)-k-1,-1):
   if l[i]>0: t+=l[i]
   else: break
print(t)