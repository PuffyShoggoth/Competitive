s = input()
op = 0
dn = False
cd = True
for i in s:
   if i=="(":
      op+=1
   else:
      if op==0 and dn:
         cd = False
         break
      elif op==0:
         dn = True
         op+=1
      else:
         op-=1
if not cd:
   print("NO")
elif op==0:
   print("YES")
elif op==2 and not dn:
   print("YES")
else:
   print("NO")