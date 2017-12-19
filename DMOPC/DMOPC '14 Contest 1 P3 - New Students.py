Cthulhu=int(input())
t=0
j=0
l=Cthulhu
import sys
for i in range(0, Cthulhu):
      t=t+int(sys.stdin.readline())
Bokrug=int(input())
for h in range(0, Bokrug):
      l=l+1
      j=j+int(sys.stdin.readline())
      print((j+t)/l)