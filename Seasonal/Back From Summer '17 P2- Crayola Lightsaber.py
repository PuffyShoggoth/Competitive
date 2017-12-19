n = int(input())
l = input().split()
d = {}
for i in l:
   if i not in d: d[i]=0
   d[i]+=1
if len(d) ==1: print(1)
else:
   sq = 0
   ex = 0
   l = [d[i] for i in d]
   l.sort()
   l.reverse()
   if l[0] > sum(l[1:])+1:
      print(sum(l[1:])*2+1)
   else:
      print(sum(l))