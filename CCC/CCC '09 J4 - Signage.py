l=['WELCOME','TO','CCC','GOOD', 'LUCK', 'TODAY']
d={}
nu=int(input())
c=0
while l:
   if c not in d:
      d[c]=[[l[0]], len(l[0])+1]
      l.remove(l[0])
   elif (d[c][1]+len(l[0]))>nu:
         d[c][1]=d[c][1]+1-len(d[c][0])
         c=c+1
   else: 
      d[c][0].append(l[0])
      d[c][1]=d[c][1]+len(l[0])+1
      l.remove(l[0])
d[max(d)][1]=d[max(d)][1]+1-len(d[max(d)][0])
for i in d:
   e=''
   h=nu-d[i][1]+1
   if (len(d[i][0])-1)==0: 
      po=h
      op=0
   else: 
      po=h//(len(d[i][0])-1)
      op=h%(len(d[i][0])-1)
   for k in range(0, len(d[i][0])-1):
      e=e+d[i][0][k]+'.'*po
      if op>0:e=e+'.'
      op=op-1
   e=e+d[i][0][len(d[i][0])-1]
   if len(d[i][0])==1:
      e=e+'.'*po
   print(e)