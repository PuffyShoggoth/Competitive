import math
a, b=map(int, input().split())
l=0
if a<0 and b==0: print(1)
elif a<0 and b>0: print(int(math.sqrt(b))+1)
elif a<0 and b<0: print(l)
else:
  if int(math.sqrt(a))**2==a: l+=1
  a=int(math.sqrt(a)+1)
  b=int(math.sqrt(b))
  l+=b-a+1
  print(l)