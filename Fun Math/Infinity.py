def tohexa(x):
   tot=0
   for i in range(0, len(x)):
      if x[len(x)-i-1].isupper():
         tot+=(ord(x[len(x)-i-1])-ord("A")+10)*(16**i)
      elif x[len(x)-i-1].islower():
         tot+=(ord(x[len(x)-i-1])-ord("a")+10)*(16**i)
      else: tot+=int(x[len(x)-i-1])*(16**i)
   return tot
if tohexa(input())+tohexa(input())>1061109567:
   print("Yes")
else:
   print("No")