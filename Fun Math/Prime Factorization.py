import math
n=int(input())
for i in range(n):
   f=int(input())
   for k in range(2, int(math.sqrt(f))+2):
      while f%k==0:
         print(k, end=" ")
         f=f//k
   if f!=1: print(f)
   else: print()