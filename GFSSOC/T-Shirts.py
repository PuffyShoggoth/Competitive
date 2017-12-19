p=[int(i) for i in input().split()]
h=[float(i) for i in input().split()]
g=sum(p)//4
tot=0.00
if p[2]>=g: 
   p[2]=p[2]-g
else:
   g=g-p[2]
   p[2]=0
   if p[1]>=g:
       p[1]=p[1]-g
   else: 
      g=g-p[1]
      p[1]=0
      p[0]=p[0]-g
for i in range(0, 3):
   tot+=float(p[i]*h[i])
tot=round(tot, 2)
if tot*10==int(tot*10): tot=str(tot)+"0"
print(tot)