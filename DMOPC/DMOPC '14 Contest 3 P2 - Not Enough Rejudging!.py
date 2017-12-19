n=int(input())
l=[]
ir=20
for i in range(0, n):
   l.append(input())
h=l.count('WA')*30/100
for i in range(0, n):
   if l[i]=='AC': print('AC')
   elif l[i]=='WA':
      if h>=1: 
       print('AC')
       h=h-1
      else: print('WA')
   elif l[i]=='TLE': print('WA')
   else:
      if ir>10: 
         print('AC')
         ir=ir-1
      elif ir>0:
         print('WA')
         ir=ir-1
      else: print('IR')