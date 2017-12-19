r, c=map(int, input().split())
rm=[]
from collections import defaultdict
flg={}
tr=0
for i in range(0, r):
   rm.append(input())

for i in range(0, r):
   for j in range(0, c):
      if rm[i][j]!="X": flg[tuple([i, j])]=0
      else: flg[tuple([i, j])]=1
def dfs(x, y):
   p=[tuple([x, y])]
   while len(p)>0:
      f=p.pop()
      flg[f]=1
      if f[0]>0 and flg[tuple([f[0]-1, f[1]])]!=1:
         p.append(tuple([f[0]-1, f[1]]))
      if f[0]<len(rm)-1 and flg[tuple([f[0]+1, f[1]])]!=1:
         p.append(tuple([f[0]+1, f[1]]))
      if f[1]>0 and flg[tuple([f[0], f[1]-1])]!=1:
         p.append(tuple([f[0], f[1]-1]))
      if f[1]<len(rm[0])-1 and flg[tuple([f[0], f[1]+1])]!=1:
         p.append(tuple([f[0], f[1]+1]))
for i in range(0, r):
   for j in range(0, c):
      if flg[tuple([i, j])]==0: 
         tr+=1
         dfs(i, j)
print(tr)