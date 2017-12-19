import sys
w=int(input())
c=int(input())
l=[]
for i in range(0, c):
   l.append(int(sys.stdin.readline()))
csum=0
carso=0
for i in range(0, c):
   csum=csum+ l[i]
   if i>3: csum=csum- l[i-4] 
   if csum>w: break
   carso=carso+ 1
       
print(carso)