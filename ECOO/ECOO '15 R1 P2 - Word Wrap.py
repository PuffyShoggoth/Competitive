for j in range(10):
   w=int(input())
   l=input().split()
   i=0
   c=0
   cl=[]
   while i<len(l):
      if (c+len(l[i]))<=w:
         c+=len(l[i])+1
         cl.append(l[i])
         i+=1
      elif len(l[i])>w:
         if len(cl)>0:
            for k in cl:
               print(k, end=" ")
            print()
         print(l[i][0:w])
         l[i]=l[i][w:len(l[i])]
         c=0
         cl=[]
      else:
         for k in cl:
               print(k, end=" ")
         print()
         cl=[]
         c=0
   if len(cl)>0:
            for k in cl:
               print(k, end=" ")
            print()
   print("=====")