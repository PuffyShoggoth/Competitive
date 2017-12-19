c=int(input())
l=[-1, -1]
for i in range(c):
   tp=input().split()
   ins=int(tp[0])
   if ins==4:
      if (l[0]!=(-1) and l[1]!=(-1)):
         print("false true")
      elif (l[0]!=(-1)):
         print("false")
      elif (l[1]!=(-1)):
         print("true")
      else:
         print()
   else: 
      if (tp[1]=="true"):bl=1
      else: bl=0
      if ins==1:
         if l[bl]==-1:
            print("true")
            l[bl]=bl
         else:
            print("false")
      elif ins==2:
         if l[bl]==-1:
            print("false")
         else:
            print("true")
            l[bl]=-1
      else:
         if l[bl]==-1:
            print(-1)
         elif bl==1 and l[0]!=(-1): print(1)
         else: print(0)