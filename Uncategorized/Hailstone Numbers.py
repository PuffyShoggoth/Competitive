n=int(input())
to=0
while n!=1:
   if n%2==0: n=n//2
   else: n=n*3+1
   to=to+1
print(to)