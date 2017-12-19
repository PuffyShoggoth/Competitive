v = [int (i) for i in input().split()]
n=int(input())
for i in range(n):
   nl=input().split()
   p= True
   for i in range(3):
      if v[i]<int(nl[i+1])/int(nl[0]): p=False
   if p: 
      for i in nl[4:]:
         print(i, end=" ")
      print()