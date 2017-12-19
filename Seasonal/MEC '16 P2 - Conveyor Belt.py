l=int(input())
sp=input()
ep=input()
n=-1
sl=[]
for i in range(l):
   if sp[i]==ep[0]: sl.append(i)
for i in range(0, len(sl)):
      if sp[sl[i]:l]==ep[0:l-sl[i]] and sp[0:sl[i]]==ep[l-sl[i]:l]:
         if (sl[i])>(l/2):
            n="R"+str(l-sl[i])
         else:
            n="L"+str(sl[i])
         break
print(n)