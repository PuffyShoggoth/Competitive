def ismonk(s, st, ed):
   if ed<st: return False
   if ed == st and s[ed]=="A": return True
   elif ed==st: return False
   if s[st]=="N" or s[ed]=="N":
      return False
   if s[st]=="B":
      nb = 0
      for i in range(st+1, ed+1):
         if s[i]=="B":
             nb+=1
         if s[i]=="S":
            if nb > 0:
                nb -=1
                continue
            if i==ed: return ismonk(s, st+1, i-1)
            elif s[i+1]!="N": return False
            elif i+1 == ed: return False
            return ismonk(s, st+1, i-1) and ismonk(s, i+2, ed)
      return False
   elif s[st]=="S":
      return False
   else:
      if s[st+1]=="N":
         return ismonk(s, st+2, ed)
      else:
         return False

while True:
   i = input()
   if i=="X": 
      break
   if ismonk(i, 0, len(i)-1): print("YES")
   else: print("NO")