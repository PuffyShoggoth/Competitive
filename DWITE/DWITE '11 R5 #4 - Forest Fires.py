dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]
for dnr in range(5):
   trs = [[-1 for i in range(10)] for j in range(10)]
   l = []
   td = []
   mx = 0
   for i in range(10):
      l.append(input())
      for j in range(10):
         if l[-1][j]=="F":
            td.append([[i, j], 0])
   input()
   while len(td)>0:
      ct = td.pop()
      if ct[0][0]<0 or ct[0][1]<0 or ct[0][0]>=10 or ct[0][1]>=10: continue
      if trs[ct[0][0]][ct[0][1]]!=-1 and trs[ct[0][0]][ct[0][1]]<=ct[1]: continue
      if l[ct[0][0]][ct[0][1]]==".": continue
      trs[ct[0][0]][ct[0][1]]=ct[1]
      for dr in dirs:
         td.append([[ct[0][0]+dr[0], ct[0][1]+dr[1]], ct[1]+1])
   imp = False
   for i in range(10):
      for j in range(10):
         if l[i][j]=="T":
            if trs[i][j]==-1:
               print(-1)
               imp = True
               break
            else:
               mx = max(mx, trs[i][j])
      if imp: break
   if not imp:
      print(mx)