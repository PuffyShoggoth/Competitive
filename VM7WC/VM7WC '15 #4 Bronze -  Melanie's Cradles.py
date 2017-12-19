import math
r=int(input())
t=r*2+1
for i in range(1, r+1):
   t+=(int(math.sqrt(r*r-i*i))*2+1)*2
print(t)