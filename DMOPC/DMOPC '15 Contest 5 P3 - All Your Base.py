e, n=map(int, input().split())
l=[int (x) for x in input().split()]
def base(b, a):
   cb=0
   sm=0
   while b>0:
      sm+=b%10*(a**cb)
      cb+=1
      b=b//10
   return sm
k=l[n-1]
for i in range(2, n+1):
   k=base(l[n-i], k)
print(base(e, k))