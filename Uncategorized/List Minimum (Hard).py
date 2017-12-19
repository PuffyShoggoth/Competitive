Cthulhu=int(input())
q=1000000000
L=[]
import sys
for i in range(0, Cthulhu):
  L.append(int(sys.stdin.readline()))
L.sort()
for i in range(0, Cthulhu):
  print(L[i])