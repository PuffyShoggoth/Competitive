s=input()
u=0
l=0
for i in range(len(s)):
   if s[i].isupper(): u+=1
   elif s[i].islower(): l+=1
if u>l: print(s.upper())
elif l>u: print(s.lower())
else: print(s)