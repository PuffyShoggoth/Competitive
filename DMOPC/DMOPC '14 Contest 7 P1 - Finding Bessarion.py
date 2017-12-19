i=int(input())
f=[input() for k in range(i)]
if "Bessarion" in f and i>=3:
 h=f.index("Bessarion")
 if h==0: 
   if (f[1]=="Leslie" or f[1]=="Bayview") and ("Bayview" not in f[2: i] and "Leslie" not in f[2:i]):
      print("Y")
   else:
      print("N")
 elif h==i-1:
   if (f[i-2]=="Leslie" or f[i-2]=="Bayview") and ("Bayview" not in f[0: i-2] and "Leslie" not in f[0:i-2]):
         print("Y")
   else: print("N")
 else: 
   if (f[h-1]=="Leslie" or f[h-1]=="Bayview") and (f[h+1]=="Leslie" or f[h+1]=="Bayview"):
         print("Y")
   else: print("N")
else:
   if i<3: print("N")
   elif "Leslie" and "Bayview" in f: 
      print("N")
   elif "Leslie" in f[1:i-1] or "Bayview" in f[1:i-1]:
      print("N")
   else: print("Y")