for booyakasha in range(0, 10):
  l=[input() for i in range(16)]
  r=[["-" for i in range(16)] for i in range(16)]
  c=[["-" for i in range(16)] for i in range(16)]
  nf=0
  for i in range(16):
      for k in range(16): 
         if l[i][k]!="-": 
            if not l[i][k].isdigit(): 
               r[i][k]=(10+ord(l[i][k])-ord("A"))
               c[k][i]=(10+ord(l[i][k])-ord("A"))
            else:
               r[i][k]=int(l[i][k])
               c[k][i]=int(l[i][k])
  for i in range(16):
      for k in range(16):
       if r[i][k]=='-':
         uuhh=True
         for p in range(16):
            if not uuhh: break
            if p not in r[i] and p not in c[k]:
               n=True
               for erw in range((i//4)*4, (i//4)*4+4):
                     if p in r[erw][(k//4)*4:(k//4)*4+4]: 
                        n=False
                        break
               if n==False: continue
               else:
                     r[i][k]=p
                     c[k][i]=p
                     nf+=1
                     uuhh=False
  print(nf)