import sys
t = int(sys.stdin.readline())
for dnr in range(t):
   l = sys.stdin.readline().split()
   nmb = l[2].split("x")
   a = 0
   b = 0
   print("y' =", end=" ")
   if "x" not in l[2]:
      print(0)
   else:
      if len(nmb[0])==0:
         a=1
      elif nmb[0][0]=="-" and len(nmb[0]) == 1:
         a=-1
      else:
         a=int(nmb[0])
      if "^" in l[2]: b = int(nmb[1][1:])
      else: b=1
      ab=a*b
      b-=1
      if ab==0: print(0)
      else:
         if ab==-1: print("-", end="")
         elif ab!=1: print(ab, end="")
         elif ab==1 and b==0: print(1, end="")
         if (b==1): print("x")
         elif (b==0) and ab==-1: print(1)
         elif (b==0): print()
         else: print("x^"+str(b))