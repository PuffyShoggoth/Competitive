n=int(input())
sumn=0
prev=0
prev=[]
for i in range(0, n):
   h=int(input())
   if h!=0: 
      sumn=sumn+h
      prev.append(h)
   else: 
      sumn=sumn-prev[len(prev)-1]
      del prev[len(prev)-1]
print(sumn)