n=int(input())
k=[int(x) for x in input().split()]
ap=[]
m=0
for i in range(n):
   p=[int(x) for x in input().split()]
   ap.append(tuple([k[p[0]-1]*p[3], 10-p[1]]))
   m=max(m, p[2])
m=180-m
for i in ap:
   if i[1]==0: print(0)
   elif i[0]<=m: print(i[1])
   else: print("The kemonomimi are too cute!")