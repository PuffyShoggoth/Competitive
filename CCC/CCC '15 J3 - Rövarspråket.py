h=input()
cv=['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',  'v', 'w', 'x', 'y', 'z']
c=['b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r','s', 't', 'v', 'w', 'x', 'y', 'z']
v=['a', 'e', 'i', 'o', 'u']
def nv(x):
   i=''
   k=''
   l=57
   b=57
   for po in range(cv.index(x), len(cv)):
      if cv[po] in v: 
         i=cv[po]
         break
   for po in range(cv.index(x), -1, -1):
      if cv[po] in v: 
         k=cv[po]
         break
   if i in cv:
       l=cv.index(i)
   if k in cv:
       b=cv.index(k)
   if l!=57: l=cv.index(x)-l
   if b!=57: b=cv.index(x)-b
   if l<0: l=l*-1
   if b<0: b=b*-1
   if l==57: return k
   elif b==57: return i
   else: 
      if b<=l: return k
      else: return i
def tr(x):
   if x=="z":
      k="z"
   else: k=c[c.index(x)+1]
   return x+nv(x)+k
fstring=''
for i in range(0, len(h)):
   if h[i] in c: 
      fstring=fstring+tr(h[i])
   else: fstring=fstring+h[i]
print(fstring)