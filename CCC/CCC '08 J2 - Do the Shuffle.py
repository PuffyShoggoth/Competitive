l=["A", "B", "C", "D", "E"]
while True:
   b=int(input())
   n=int(input())
   if b==1:
      for i in range(n):
         k=l.pop(0)
         l.append(k)
   elif b==2:
      for i in range(n):
         k=l.pop()
         l=[k]+l
   elif b==3:
      for i in range(n):
         k=l[0]
         t=l[1]
         l[0]=t
         l[1]=k
   else: 
      print(" ".join(l))
      break