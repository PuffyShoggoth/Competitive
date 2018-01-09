seive = [True for i in range(100005)]
seive[0]=False
seive[1]=False
for i in range(2, 317):
   if seive[i]:
      for j in range(i**2, 100005, i):
         seive[j]=False
import sys
n = int(sys.stdin.readline())
l = [int(x) for x in sys.stdin.readline().split()]
tt = 0
for i in l:
   if seive[i]: tt+=1
print(tt)