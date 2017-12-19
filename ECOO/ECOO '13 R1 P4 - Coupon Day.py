def lmkr(x):
   if x=="$5": return 0
   elif x=="$10": return 1
   elif x=="$50": return 2
   elif x=="10%": return 3
   elif x=="20%": return 4
   elif x=="TAX": return 5
   elif x=="BOGO": return 6
def HST(x):
   return round(x*1.13, 2)
def tnpoff(x):
   return HST(x*0.90)
def tpoff(x):
   return HST(x*0.80)
def tdoff(x):
   return HST(max(x-10, 0))
def fdoff(x):
   return HST(max(x-5, 0))
def ffdoff(x):
   return HST(max(x-50, 0))
def con(x, y):
   if y==0: return fdoff(x)
   elif y==1: return tdoff(x)
   elif y==2: return ffdoff(x)
   elif y==4: return tpoff(x)
   elif y==3: return tnpoff(x)
   elif y==5: return x
d={}
def bp(x, y):
   if tuple(x+[-7]+y) in d: return d[tuple(x+[-7]+y)]
   if len(x)==0: return 0
   d[tuple(x+[-7]+y)]=999999
   t=x[:]
   m=t.pop()
   d[tuple(x+[-7]+y)]=min(d[tuple(x+[-7]+y)], bp(t, y)+HST(m))
   if y[6]!=0 and len(t)!=0: 
           for dudu in range(0, len(t)):
               ty=y[:]
               tx=t[:]
               ty[6]-=1
               f=tx.pop(dudu)
               d[tuple(x+[-7]+y)]=min(d[tuple(x+[-7]+y)], bp(tx, ty)+HST(m))
   for k in range(0, 6):
       if y[k]!=0:
               ty=y[:]
               ty[k]-=1
               d[tuple(x+[-7]+y)]=min(d[tuple(x+[-7]+y)], bp(t, ty)+con(m, k))
   return d[tuple(x+[-7]+y)]

for jkj in range(0, 5):
   li=[]
   lc=[0]*7
   k=int(input())
   for i in range(0, k):
      li.append(float(input()))
   li.sort()
   k=int(input())
   for i in range(0, k):
      m=input()
      lc[lmkr(m)]+=1
   if lc[6]>1:lc[6]=1
   ks=format(round(bp(li, lc), 2), '.2f')
   print("The best price is $"+ks)