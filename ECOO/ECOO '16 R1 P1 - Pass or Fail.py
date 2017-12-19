for i in range(10):
   s=0
   t, a, p, q=map(int, input().split())
   n=int(input())
   for k in range(n):
      l=[int(x) for x in input().split()]
      m=l[0]*t+l[1]*a+l[2]*p+l[3]*q
      if m>=5000: s+=1
   print(s)