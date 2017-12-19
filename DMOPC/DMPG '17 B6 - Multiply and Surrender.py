import math
import sys
tt = 0
n = int(sys.stdin.readline())
for i in sys.stdin.readline().split():
   tt+=math.log(int(i), 2)
print(int(1+tt))