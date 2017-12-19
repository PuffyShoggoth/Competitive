from collections import defaultdict
i=int(input())
j=int(input())
squares=defaultdict(int)
both=0
if round(i**(1/6))**6<i:
   h=int(i**(1/6))+1
else: h=round(i**(1/6))
if round(j**(1/6))**6>j:
   k=round(j**(1/6))
else: k=round(j**(1/6))+1
for l in range(h, k):
      both+=1
print(both)