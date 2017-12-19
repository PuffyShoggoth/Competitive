a=input()
cb=[]
def gno(x):
   if len(x)==1: return [x]
   tp=[]
   for i in range(0, len(x)):
      tpl=gno(x[0:i]+x[i+1:len(x)])
      for k in tpl:
         tp.append(x[i]+k)
   return tp
cb=gno(a)
cb.sort()
for i in cb: print(i)