import sys
import bisect
k = int(sys.stdin.readline())
nk = [int(x) for x in sys.stdin.readline().split()]
nk.sort()
n = int(input())
for i in range(n):
   f = int(sys.stdin.readline())
   print(f-bisect.bisect_right(nk, f))