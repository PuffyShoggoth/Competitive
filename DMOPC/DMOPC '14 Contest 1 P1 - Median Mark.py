n=int(input())
s=[]
for i in range(n):
   s.append(int(input()))
s.sort()
if len(s)%2==0:
   if (s[len(s)//2]+s[len(s)//2-1])/2>=(s[len(s)//2]+s[len(s)//2-1])//2+0.5: 
      print((s[len(s)//2]+s[len(s)//2-1])//2+1)
   else: print((s[len(s)//2]+s[len(s)//2-1])//2)
else: 
   print(s[len(s)//2])