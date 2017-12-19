import sys
h=int(input())
f=[sys.stdin.readline() for x in range(h)]
g=[sys.stdin.readline() for x in range(h-1)]
f.sort()
g.sort()
k=False
for i in range(h-1):
   if f[i] != g[i]: 
      k=True
      print(f[i])
      break
if k==False:
   print(f[len(f)-1])