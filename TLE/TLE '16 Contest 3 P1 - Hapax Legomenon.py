n=int(input())
d={}
sm=0
for i in range(n):
   t=input()
   if t in d: d[t]+=1
   else: d[t]=0
for j in d:
   if d[j]==0: sm+=1
print(sm)