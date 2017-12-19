num=int(input())
sumn=0
for i in range(0, 6):
   for k in range(i, 6):
    if i+k==num: sumn=sumn+1
print(sumn)