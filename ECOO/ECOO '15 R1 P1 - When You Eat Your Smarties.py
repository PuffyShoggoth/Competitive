for i in range(10):
   l=[]
   n=input()
   t=0
   while n!="end of box":
      l.append(n)
      n=input()
   p=["brown", "violet", "blue", "pink","yellow", "green", "orange"]
   for i in p: 
      k=l.count(i)
      t+=13*(k//7)
      if k%7!=0: t+=13
   k=l.count("red")
   t+=16*k
   print(t)