def fact(x):
   n=1
   for i in range(1, x+1):
      n=n*i
   return n
k=int(input())
l=[]
for i in range(1, k+1):
   l.append(i)
q=int(input())
for qqq in range(q):
   f=int(input())
   ln=l[:]
   for i in range(k, 0, -1):
      p=f//fact(i-1)
      print(ln[p], end=" ")
      ln.remove(ln[p])
      if i*f//(fact(i-1))!=0:
         f=f%fact(i-1)
   print()