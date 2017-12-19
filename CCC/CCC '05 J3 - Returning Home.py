alld=[]
allp=[]
while True:
   d=input()
   p=input()
   if d=='R': d='LEFT'
   elif d=='L': d='RIGHT'
   alld.append(d)
   if p=='SCHOOL': break
   allp.append(p)
for i in range(len(allp)-1, -1, -1):
   print('Turn',alld[i+1],'onto', allp[i], 'street.')
print('Turn', alld[0], 'into your HOME.')