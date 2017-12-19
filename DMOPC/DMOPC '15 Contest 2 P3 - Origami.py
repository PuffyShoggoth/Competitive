n, k=map(int, input().split())
cts=0
p=1
while n>p:
   if k>=p: 
      p=p*2
      cts+=1
   else:
      t=p//k
      p+=k*t
      cts+=t
cts-=(p-n)//k
print(cts)