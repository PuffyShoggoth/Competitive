from collections import defaultdict
am=[0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000]
mn=int(input())
mx=int(input())
d=defaultdict(int)
d[0]=1
n=int(input())
for i in range(0, n):
   am.append(int(input()))
am.sort()
for i in range(1, len(am)):
   for k in range(0, i):
      if mx>=(am[i]-am[k])>=mn: d[i]+=d[k]
print(d[len(am)-1])