t=int(input())
for i in range(t):
   r=int(input())
   c=int(input())
   rds=[[-1 for i in range(22)] for i in range(22)]
   l=[]
   for i in range(r):
      l.append(input())
   q=[tuple([0, 0, 1])]
   while len(q)>0:
      m=q.pop(0)
      e=m[2]+1
      if m[0]<0 or m[0]>=r or m[1]<0 or m[1]>=c or rds[m[0]][m[1]]!=-1: continue
      if l[m[0]][m[1]]=="*": continue
      rds[m[0]][m[1]]=e-1
      if l[m[0]][m[1]]=="+" or l[m[0]][m[1]]=="-":
          q.extend([tuple([m[0], m[1]-1, e]), tuple([m[0], m[1]+1, e])])
      if l[m[0]][m[1]]=="|" or l[m[0]][m[1]]=="+": 
         q.extend([tuple([m[0]+1, m[1], e]), tuple([m[0]-1, m[1], e])])
   print(rds[r-1][c-1])