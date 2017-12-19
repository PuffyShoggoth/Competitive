f=int(input())
r=int(input())
c=int(input())
rms=[]
d={}
fls=[]
for i in range(r):
   rms.append(input())
for i in range(r):
   for j in range(c):
      if rms[i][j]=="I": d[tuple([i, j])]=1
      else: d[tuple([i, j])]=0
def dfs(x, y, d):
   s=[]
   trs=0
   d[tuple([x, y])]=1
   s.append(tuple([x, y]))
   while len(s)>0:
      t=s.pop()
      trs+=1
      if t[0]>0 and d[tuple([t[0]-1, t[1]])]==0: 
         s.append(tuple([t[0]-1, t[1]]))
         d[tuple([t[0]-1, t[1]])]=1
      if t[0]<(len(rms)-1) and d[tuple([t[0]+1, t[1]])]==0: 
         s.append(tuple([t[0]+1, t[1]]))
         d[tuple([t[0]+1, t[1]])]=1
      if t[1]>0 and d[tuple([t[0], t[1]-1])]==0: 
         s.append(tuple([t[0], t[1]-1]))
         d[tuple([t[0], t[1]-1])]=1
      if t[1]<(len(rms[0])-1) and d[tuple([t[0], t[1]+1])]==0: 
         s.append(tuple([t[0], t[1]+1]))
         d[tuple([t[0], t[1]+1])]=1
   return tuple([trs, d]) 
for i in range(r):
   for j in range(c):
      if d[tuple([i, j])]==0:
         tmt=dfs(i, j, d)
         fls.append(tmt[0])
         d=tmt[1]
fls.sort()
fls.reverse()
i=0
while i<len(fls) and f-fls[i]>=0: 
   f-=fls[i]
   i+=1
if i==1:print(i,"room,", f, "square metre(s) left over")
else: print(i,"rooms,", f, "square metre(s) left over")