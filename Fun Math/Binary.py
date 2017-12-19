t=int(input())
i=0
def binary(x):
   if x==1: return 1
   elif x==0: return 0
   else: 
       s=str(x%2)
       return str(binary(x//2))+s
def spacing(x):
   if len(x)==4: return x
   elif len(x)<4: return str(0)*(4-len(x))+x
   else: return spacing(x[0:len(x)-4])+' '+x[len(x)-4:len(x)]
for q in range(0, t):
   n=int(input())
   print(spacing(str((binary(n)))))