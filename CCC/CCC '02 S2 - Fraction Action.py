noom=int(input())
denom=int(input())
num=noom//denom
fra=noom%denom
for i in range(1, denom//2+1):
   if fra%i==0 and denom%i==0:
      fra=fra/i
      denom=denom/i
if num==0 and fra==0: print('0')
elif num==0: print(str(int(fra))+'/'+str(int(denom)))
elif fra==0:print(int(num))
else: print(int(num),str(int(fra))+'/'+str(int(denom)))