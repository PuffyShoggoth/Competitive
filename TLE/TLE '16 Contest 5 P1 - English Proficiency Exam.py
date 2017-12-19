vowels=["a", "e", "i", "o", "u"]
rd=True
for k in input().split():
   smv=0
   for i in k:
      if i in vowels: smv+=1
   if abs(smv*2-len(k))>1 or (len(k)==1 and smv==0): 
      rd=False
      break
if rd: print("readable")
else: print("not readable")