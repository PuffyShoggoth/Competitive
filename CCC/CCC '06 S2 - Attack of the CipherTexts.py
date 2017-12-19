ptext=input()
entext=input()
c={}
for i in range(len(entext)):
   c[entext[i]]=ptext[i]
detext=input()
nptext=''
for i in range(len(detext)):
   if detext[i] not in c: nptext=nptext+'.'
   else: nptext=nptext+c[detext[i]]
print(nptext)