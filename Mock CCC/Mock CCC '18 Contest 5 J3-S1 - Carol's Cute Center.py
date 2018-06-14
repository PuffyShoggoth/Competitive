n, x = map(int, input().split())
nl=0
ng=0
nx=0
l = [int(i) for i in input().split()]
for i in l:
   if i<x: nl+=1
   elif i>x: ng+=1
   else: nx+=1
tt = 0
if nx>=3: tt+=(nx*(nx-1)*(nx-2))//6
if nx>=2: tt+=(nl+ng)*nx*(nx-1)//2
if nx>=1: tt+=nx*nl*ng
print(tt)