from collections import defaultdict

r=defaultdict(list)

v=0

u=False

for i in range(0, 4):
   a, b, c, d=map(int, input().split())
   l=[a, b, c, d]
   for k in range(0, 4):
      if l[k]==1 and k!=i: r[i].append(k)
      if a==0 and b==0 and c==0 and d==0: u=True

for p in range(0, 4):
   v=v+len(r[p])

if v==6 and u==False:
   print('Yes')
else: print('No')