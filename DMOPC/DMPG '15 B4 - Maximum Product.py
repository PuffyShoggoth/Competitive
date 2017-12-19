h=int(input())
l=[]
c=1
if h==0: c=0
if h==1: c=int(input())
else: 
 for i in range(0, h):
   z=int(input())
   if z==0: r=True
   if z<0: l.append(z)
   elif z!=0:c=c*z
if len(l)%2==0 and len(l)!=0:
    for i in range(0, len(l)):
        c=c*l[i]
elif len(l)!=0:
    l.sort()
    for i in range(0, len(l)-1):
        c=c*l[i]
if len(l)==1 and h==2 and r==True:
    c=0
print(c)