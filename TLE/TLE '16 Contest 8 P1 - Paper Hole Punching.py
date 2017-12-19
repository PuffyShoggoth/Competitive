t = input()
n = int(input())
for i in range(n):
   k = input()
   cu = True
   for j in t:
      if j not in k: 
         cu = False
         break
   if (cu): print("yes")
   else: print("no")