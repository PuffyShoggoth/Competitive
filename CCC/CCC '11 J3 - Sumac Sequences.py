a=int(input())
b=int(input())
c=2
while True:
   c=c+1
   a, b= b, (a-b)
   if b>a: break
print(c)