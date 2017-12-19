import sys
h=int(input())
j=[]
readings={1005:0}
for i in range(0, h):
   s=int(sys.stdin.readline())
   if s not in readings: readings[s]=1
   else: readings[s]=readings[s]+1

o=1005
p=1005
big=[]
twobig=[]
for i in readings:
  if readings[i]>readings[o]: 
      p=o
      o=i
      twobig=big[:]
      big=[i]
  elif readings[i]==readings[o]:
         big.append(i)
  elif readings[i]>readings[p]: 
         p=i
         twobig=[i]
  elif readings[i]==readings[p]:
         twobig.append(i)
if len(big)>1: print(max(big)-min(big))
else: print(max(max(big[0], min(twobig))-min(big[0], min(twobig)), max(big[0], max(twobig))-min(big[0], max(twobig))))