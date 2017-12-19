n=int(input())
def fp(tn):
  t=1
  if (tn&1)>0: t=2
  p=2
  for i in range(1, 59):
   p=(p*p)%1000000013
   if (tn&(1<<i)):
      t=(t*p)%1000000013
  return t
if n<2: print(1)
else:
   q=n%8
   if q==7 or q==1 or q==0: k=1
   elif q>=3 and q<=5: k=-1
   else: k=0
   rt=fp((n//2)-1)
   tt=(rt*rt)%1000000013
   if n%2==1: tt*=2
   print((rt*k+tt)%1000000013)