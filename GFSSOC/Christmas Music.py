n=int(input())
f=input()
k=["C", "D", "E", "F", "G", "A", "B"]
j=0
p=True
def ton(x):
   return k.index(x[0])+(int(x[1])-1)*7
f=ton(f)
for i in range(0, n-1):
   if not p: break
   g=ton(input())
   if f-g>=7 or f-g<=-7: p=False
   if f-g>=4:
      if j!=0: p=False
      else: j=1
   elif f-g<=-4:
      if j!=0: p=False
      else: j=-1
   else:
      if j<0:
         if f-g<0: p=False
         else: j=0
      elif j>0:
         if f-g>0: p=False
         else: j=0
   f=g
if p: print("Melodious!")
else: 
   print('Salieri\'s music')