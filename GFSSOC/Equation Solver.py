h=input().split()
sumn=int(h[0])
for i in range(0, len(h)):
   if h[i]=='P': sumn=sumn+int(h[i+1])
   if h[i]=='M': sumn=sumn-int(h[i+1])
   if h[i]=='=': print(sumn)