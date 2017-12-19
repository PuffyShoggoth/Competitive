g={}
m={}
t=[]
j=int(input())
for i in range(j):
   p=input().split()
   if p[1]=="general":
      m[int(p[2])]=p[0]
   else:
      g[int(p[2])]=p[0]
if len(g)>0:
 t.append(g[max(g)])
 del g[max(g)]
for i in range(0, 2):
  if len(g)>0 and len(m)>0:
   if max(g)>max(m):
     t.append(g[max(g)])
     del g[max(g)]
   else: 
     t.append(m[max(m)])
     del m[max(m)]
  elif len(g)>0:
      t.append(g[max(g)])
      del g[max(g)]
  elif len(m)>0:
      t.append(m[max(m)])
      del m[max(m)]
if len(t)==0: print("No ECOO :(")
for i in range(0, 3):
   if len(t)==0: break
   print(min(t))
   t.remove(min(t))