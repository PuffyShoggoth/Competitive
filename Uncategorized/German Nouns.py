m=int(input())
for i in range(0, m):
   h=input().split()
   sumn=0
   for i in range(0, len(h)):
      if 65<=ord(h[i][0])<=90: sumn=sumn+1
   print(sumn)