import math
n = int(input())
l=[]
for i in range(0, math.ceil(n/16)):
   l.append(input().split())
if (n<2): print("COM")
elif (l[0][0]!="4D") or (l[0][1]!="5A"): print("COM")
else:
   if len(l)<4 or len(l[3])<16: print("MZ")
   else:
      offset = int(l[3][15]+l[3][14]+l[3][13]+l[3][12], 16)
      if (offset//16>=len(l)) or (len(l[offset//16])<=offset%16+1): print("MZ")
      else:
         hdr = chr(int(l[offset//16][offset%16], 16))+chr(int(l[offset//16][offset%16+1], 16))
         if hdr in ["NE", "LE", "PE"]: print(hdr)
         else: print("MZ")