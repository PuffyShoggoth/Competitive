lm, ln=map(int, input().split())
k=input().split()
m=[int(x) for x in k]
k=input().split()
n=[int(x) for x in k]
d=[[0 for i in range(ln)] for i in range(lm)]
if m[0]==n[0]: d[0][0]=1
for i in range(1, ln):
   if m[0]==n[i] or d[0][i-1]==1: d[0][i]=1
for i in range(1, lm):
   if d[i-1][0]==1 or m[i]==n[0]: d[i][0]=1
   for j in range(1, ln):
      d[i][j]=max(d[i-1][j], d[i][j-1])
      if m[i]==n[j]: d[i][j]=max(d[i][j], d[i-1][j-1]+1)
print(d[lm-1][ln-1])