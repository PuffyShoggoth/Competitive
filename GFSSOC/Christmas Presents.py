p=int(input())
t=int(input())
dp={}
dt={}
lp=[]
lt=[]
for i in range(0, p):
   pn=input()
   k=float(input())
   lp.append(tuple([k, pn]))
for i in range(0, t):
   tn=input()
   k=int(input())
   lt.append(tuple([k, tn]))
lp.sort()
lt.sort()
for i in range(0, len(lt)):
   print(lt[i][1], "will get a", lp[i][1])