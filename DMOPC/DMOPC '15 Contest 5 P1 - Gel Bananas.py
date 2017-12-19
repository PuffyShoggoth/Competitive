a=int(input())
b=int(input())
c=int(input())
a, b=max(a, b), min(a, b)
if a%b==0: lcm=a
else: 
   import math
   lcm=a*b
   for i in range(2, int(math.sqrt(a))+2):
      while a%i==0 and b%i==0: 
         a=a//i
         b=b//i
         lcm=lcm//i
print((c-1)//lcm+1)