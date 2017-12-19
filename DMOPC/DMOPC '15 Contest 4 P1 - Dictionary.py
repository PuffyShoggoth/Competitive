from collections import defaultdict
h=int(input())
l=defaultdict(list)
fl=[]
for i in range(0, h):
   j=input()
   if j[0] not in fl:
       fl.append(j[0])
   l[j[0]].append(j)
fl.sort()
for i in fl:
   l[i].sort()
   for k in l[i][0:len(l[i])-1]:
      print(k+", ", end="")
   print(l[i][len(l[i])-1])