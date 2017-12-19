n, m=map(int, input().split())
d={}
for i in range(1, n+1):
   d[i]=[]
for i in range(0, m):
   r, j=map(int, input().split())
   d[r].append(j)
   d[j].append(r)
def cycler(a, b, c):
   if not a: return [0]
   elif a in b: return [c-b.index(a)]
   
   else:
      f=0
      p=[]
      for i in d[a]:
         p+=cycler(i, b+[a], c+1)
      return p
q=[]
for i in range(1, n+1):
 q+=(cycler(i, [], 0))
if 6 in q: print("YES")
else: print("NO")