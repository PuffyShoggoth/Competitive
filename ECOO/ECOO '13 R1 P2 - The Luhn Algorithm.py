def value(x):
   sumn=0
   for i in range(len(x)-1, -1, -2):
      h=str(int(x[i])*2)
      for p in range(0, len(h)):
         sumn=sumn+int(h[p])
      if i>0: sumn=sumn+int(x[i-1])
   return sumn
for i in range(0, 5):
   x=''
   a, b, c, d, e=input().split()
   for i in a, b, c, d, e:
      p=value(i)%10
      if p==0: x=x+'0'
      else: x=x+str(10-p)
   print(x)