m=input().split()
p=True
a=["ch", "t", "m", "d", "b", "bd", "r"]
b=["a", "e", "i", "oo"]
c=["n", "v", "f"]
if len(m)<2:
   p=False
else: 
   for i in m:
      if not p: break
      k=i.lower()
      if len(k)<2: p=False
      elif k[len(k)-1] in b or k[len(k)-2:len(k)]=="oo": p=False
      elif k[0:2] in a:
         k=k[2:]
         l=b
      elif k[0] in a:
         k=k[1:]
         l=b
      elif k[0:2] in b:
         k=k[2:]
         l=a
      elif k[0] in b:
         k=k[1:]
         l=a
      else: p=False
      if len(k)==0: p=False
      
      while(len(k)>0):
          if not p: break
          if k[0:2] in l:
            k=k[2:]
          elif k[0] in l:
            k=k[1:]
          elif k[0] in c and len(k)==1:
               break
          else:
            p=False
          if l==a: l=b
          else: l=a
if p: print("valid")
else: print("invalid")