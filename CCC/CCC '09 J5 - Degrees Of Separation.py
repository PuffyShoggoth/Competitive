from collections import defaultdict
from collections import deque
td=input()
d=defaultdict(list)
sp=[tuple([1, [6]]), tuple([2, [6]]), tuple([3, [4, 5, 6, 15]]), tuple([4, [3, 6, 5]]), tuple([5, [3, 4, 6]]), tuple([6, [1, 2, 3, 4, 5, 7]]), tuple([7, [8, 6]]), tuple([8, [7, 9]]), tuple([9, [12, 10, 8]]), tuple([10, [9, 11]]), tuple([11, [10, 12]]), tuple([12, [9, 11, 13]]), tuple([13, [12, 14, 15]]), tuple([14, [13]]), tuple([15, [13, 3]]), tuple([16, [17, 18]]), tuple([17, [16, 18]]), tuple([18, [16, 17]])]
for i in sp:
   d[i[0]]=i[1]
def sdg(x):
   l=[]
   for i in d[x]:
      for k in d[i]:
         if k not in d[x] and k not in l and k!=x: 
            l.append(k)
   return len(l)
def bfs(x, y):
   dq=deque()
   dq.append(tuple([x, 0]))
   flg=[x]
   while len(dq)>0:   
      m=dq.popleft()
      for i in d[m[0]]:
         if i==y: return m[1]+1
         if i not in flg:
            flg.append(i)
            dq.append(tuple([i, m[1]+1]))
   return -1
while td!="q":
   if td=="i":
      x=int(input())
      y=int(input())
      d[x].append(y)
      d[y].append(x)
   elif td=="d": 
      x=int(input())
      y=int(input())
      d[x].remove(y)
      d[y].remove(x)
   elif td=="n":
      print(len(d[int(input())]))
   elif td=="f":
      r=int(input())
      print(sdg(r))
   elif td=="s":
      x=int(input())
      y=int(input())
      if x==y: print(0)
      else: 
         m=bfs(x, y)
         if m==-1: print("Not connected")
         else: print(m)
   td=input()