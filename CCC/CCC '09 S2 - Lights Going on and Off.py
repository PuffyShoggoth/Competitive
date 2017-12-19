r=int(input())
l=int(input())
lp=[[] for i in range(r)]
for i in range(r-1, -1, -1):
   lp[i].append(tuple([int (x) for x in input().split()]))
for i in range(r-2, -1, -1):
   for d in range(0, len(lp[i+1])):
      nl=[]
      for k in range(0, l):
         if lp[i+1][d][k]==lp[i][0][k]:
            nl.append(0)
         else:
            nl.append(1)
      
      if tuple(nl) not in lp[i]: lp[i].append(tuple(nl))
print(len(lp[0]))