import math
while True:
   j=int(input())
   if j==0: break
   for i in range(int(math.sqrt(j)), 0, -1):
      if j%i==0:
         print('Minimum perimeter is', 2*i+2*j//i, 'with dimensions',i,'x', j//i)
         break