n=int(input())
for pwaa in range(n):
   s=input()
   l=[]
   for i in range(0, len(s)):
      l.append(s[i:len(s)])
   l.sort()
   t=len(l[0])+1
   for i in range(1, len(l)):
      m=min(len(l[i]), len(l[i-1]))
      for k in range(min(len(l[i]), len(l[i-1]))):
         if l[i][k]!=l[i-1][k]:
            m=k
            break
      t+=len(l[i])-m
   print(t)