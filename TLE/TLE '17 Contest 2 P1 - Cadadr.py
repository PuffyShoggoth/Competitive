s=input()
eb = 0
for i in range(len(s)):
   if s[i]=="(": continue
   elif s[i]=="c": continue
   elif s[i]=="r": 
      print("x"+")"*eb)
      break
   else:
      if s[i]=="a":
         print("(car ", end="")
      else:
         print("(cdr ", end="")
      eb+=1