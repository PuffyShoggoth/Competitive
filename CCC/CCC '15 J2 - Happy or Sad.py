stg=str(input())
happy=0
sad=0
for i in range(0, len(stg)):
   if stg[i:i+3]==':-)':
      happy=happy+1
   if stg[i:i+3]==':-(':
      sad=sad+1
if sad==0 and happy==0:
   print('none')
elif sad==happy:
   print('unsure')
elif sad>happy:
   print('sad')
else:
   print('happy')