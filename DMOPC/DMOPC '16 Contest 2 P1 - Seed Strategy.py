n=int(input())
k=int(input())
l1=0
for i in range(k):
   tp=int(input())
   if (tp==2): n-=1
   elif (tp==3): n-=5
   else: l1+=1
if (l1/2 + l1%2)>n:
   print("Return")
else:
   print("Continue")