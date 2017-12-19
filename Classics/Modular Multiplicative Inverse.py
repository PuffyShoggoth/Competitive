n, m=map(int, input().split())
si=[1, 0]
q=n//m
r=[m, n%m]
while(r[1]!=0):
   si[0], si[1]=si[1], si[0]-q*si[1]
   q=r[0]//r[1]
   r[0], r[1]=r[1], r[0]%r[1]
if (si[1]<0): print(si[1]+m)
else: print(si[1])