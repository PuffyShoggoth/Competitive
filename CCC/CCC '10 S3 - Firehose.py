h=int(input())
l=[int(input()) for i in range(h)]
l.sort()
s=-1
e=0
t=1000000-l[h-1]+l[e]
def ek(v):
   np=0
   ct=0
   while np<h:
      np=bs(np, v)+1
      ct+=1
   return ct
def bs(i, v):
   st=i
   ed=len(l)-1
   while st<=ed:
      m=(st+ed)//2
      if min(abs(1000000-l[i]+l[m]), abs(l[m]-l[i]))<=v: st=m+1
      elif min(abs(1000000-l[i]+l[m]), abs(l[m]-l[i]))>v: ed=m-1
   return ed
for i in range(0, h-1):
   if min(1000000-l[i+1]+l[i], l[i+1]-l[i])>t:
      t=l[i+1]-l[i]
      e, s=i+1, i
l=l[e:h]+l[0:s+1]
k=int(input())
si=0
ei=min(abs(1000000-l[len(l)-1]+l[0]), abs(l[len(l)-1]-l[0]))
while si<ei:
   m=(si+ei)//2
   p=ek(m)
   if p<=k: ei=m
   elif p>k: si=m+1
print(ei//2+ei%2)