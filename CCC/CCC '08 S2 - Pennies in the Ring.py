import math
r=int(input())
while r!=0:
   t=r*2+1
   for i in range(1, r+1):
     t+=(int(math.sqrt(r*r-i*i))*2+1)*2
   print(t)
   r=int(input())