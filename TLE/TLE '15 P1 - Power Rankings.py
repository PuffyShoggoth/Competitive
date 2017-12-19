n, p=map(int, input().split())
d={}
s=[input() for i in range(n)]
tt=[0 for i in range(n)]
for i in range(p):
   l=[int(x) for x in input().split()]
   for i in range(n):
      tt[i]+=l[i]
for i in range(n):
   d[tt[i]]=s[i]
tt.sort()
for i in range(n):
   print(str(i+3)+".", d[tt[n-i-1]])