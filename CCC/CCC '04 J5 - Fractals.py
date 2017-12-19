xued=[]
txued=[]
xded=[]
txded=[]
yled=[]
tyled=[]
yred=[]
tyred=[]
l, w, x=map(int, input().split())
xued.append(tuple([0, w, 1]))
for i in range(l):
   for k in xued:
      f=(k[1]-k[0])//3
      txued.extend([tuple([k[0], k[0]+f, k[2]]), tuple([k[0]+f, k[0]+f*2, k[2]+f]), tuple([k[0]+f*2, k[1], k[2]])])
      tyled.append(tuple([k[2], k[2]+f, k[0]+f]))
      tyred.append(tuple([k[2], k[2]+f, k[0]+f*2]))
   for k in xded:
      f=(k[1]-k[0])//3
      txded.extend([tuple([k[0], k[0]+f, k[2]]), tuple([k[0]+f, k[0]+f*2, k[2]-f]), tuple([k[0]+f*2, k[1], k[2]])])
      tyled.append(tuple([k[2]-f, k[2], k[0]+f]))
      tyred.append(tuple([k[2]-f, k[2], k[0]+f*2]))
   for k in yled:
      f=(k[1]-k[0])//3
      tyled.extend([tuple([k[0], k[0]+f, k[2]]), tuple([k[0]+f, k[0]+f*2, k[2]-f]), tuple([k[0]+f*2, k[1], k[2]])])
      txued.append(tuple([k[2]-f, k[2], k[0]+f*2]))
      txded.append(tuple([k[2]-f, k[2], k[0]+f]))
   for k in yred:
      f=(k[1]-k[0])//3
      tyred.extend([tuple([k[0], k[0]+f, k[2]]), tuple([k[0]+f, k[0]+f*2, k[2]+f]), tuple([k[0]+f*2, k[1], k[2]])])
      txded.append(tuple([k[2], k[2]+f, k[0]+f]))
      txued.append(tuple([k[2], k[2]+f, k[0]+f*2]))
   xded=txded[:]
   xued=txued[:]
   yred=tyred[:]
   yled=tyled[:]
   txded=[]
   txued=[]
   tyred=[]
   tyled=[]
pli=[]
for i in xued:
   if i[1]>=x>=i[0] and i[2] not in pli: pli.append(i[2])
for i in xded:
   if i[1]>=x>=i[0] and i[2] not in pli: pli.append(i[2])

for i in yred: 
   if i[2]==x:
      for k in range(i[0], i[1]+1):
         if k not in pli:
             pli.append(k)
for i in yled: 
   if i[2]==x:
      for k in range(i[0], i[1]+1):
         if k not in pli:
            pli.append(k)
pli.sort()
for i in pli:
   print(i, end=" ")