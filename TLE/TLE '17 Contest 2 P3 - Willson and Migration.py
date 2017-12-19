import sys
import math
n, r = map(int, sys.stdin.readline().split())
wils = [int(x) for x in sys.stdin.readline().split()]
dst = math.sqrt((wils[0]-wils[2])**2+(wils[1]-wils[3])**2)
vxw = (wils[2]-wils[0])/dst*wils[4]
vyw = (wils[3]-wils[1])/dst*wils[4]
fm = []
for i in range(1,n):
   l = [int(x) for x in sys.stdin.readline().split()]
   dst = math.sqrt((l[0]-l[2])**2+(l[1]-l[3])**2)
   vxt = (l[2]-l[0])/dst*l[4]
   vyt = (l[3]-l[1])/dst*l[4]
   x = wils[0]-l[0]
   y = wils[1]-l[1]
   vx = vxw-vxt
   vy = vyw-vyt
   if vx==0 and vy==0: 
      if (x**2+y**2)<=r**2: print(i+1)
      continue
   t = -(x*vx+y*vy)/(vx**2+vy**2)
   if (t<0):
      if (x**2+y**2)<=r**2: print(i+1)
      continue
   d = x**2+y**2+2*(x*vx+y*vy)*t+(vx**2+vy**2)*(t**2)
   if d<=r**2:
      print(i+1)