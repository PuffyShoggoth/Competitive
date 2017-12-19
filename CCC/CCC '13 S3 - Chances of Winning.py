t=int(input())
g=int(input())
sc=[[0, 0, 0, 0]]
gtp=[]
for i in range(0, 4):
   for k in range(i+1, 4):
      gtp.append(tuple([i, k]))
for i in range(g):
   a, b, sa, sb=map(int, input().split())
   gtp.remove(tuple([min(a, b)-1, max(a, b)-1]))
   if sa>sb: sc[0][a-1]+=3
   elif sb>sa: sc[0][b-1]+=3
   else: 
      sc[0][a-1]+=1
      sc[0][b-1]+=1
tmp=[]
for k in gtp:
   for i in sc:
      tmw=i[:]
      tml=i[:]
      tmt=i[:]
      tmw[k[0]]+=3
      tml[k[1]]+=3
      tmt[k[0]]+=1
      tmt[k[1]]+=1
      tmp.extend([tmw, tml, tmt])
   sc=tmp[:]
   tmp=[]
tot=0
for i in range(0, len(sc)):
   if sc[i][t-1]==max(sc[i]) and sc[i].count(sc[i][t-1])==1: tot+=1
print(tot)