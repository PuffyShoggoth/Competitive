import sys
stops=int(input())
ron, roff=map(int, sys.stdin.readline().split())
minoff=ron
maxoff=ron
toton=0
for i in range(stops-2):
   ron, roff=map(int, sys.stdin.readline().split())
   minoff=minoff-roff
   if toton<roff:
       roff=roff-toton
       toton=0
   else:
       toton=toton-roff
       roff=0
   maxoff=maxoff-roff
   toton=toton+ron
if minoff<0: minoff=0
print(minoff)
print(maxoff)