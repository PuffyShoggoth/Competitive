import sys
t=int(input())
for i in range(t):
   n=int(input())
   l=0
   b=[]
   c=[int(sys.stdin.readline()) for i in range(n)]
   for i in range(n-1, -1, -1):
      while(len(b)>0 and b[len(b)-1]==l+1):
         k=b.pop()
         l+=1
      if c[i]==l+1: l+=1
      else: b.append(c[i])
   if len(b)==0 or l+1==b[len(b)-1]: print("Y")
   else: print("N")