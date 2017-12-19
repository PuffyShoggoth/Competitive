n, l=map(int, input().split())
d={}
words=[]
def worder(x, r, l):
   if r==len(d) or l==0: return
   for i in range(r, len(d)):
      for k in d[i]:
         words.append(x+k)
         worder(x+k, i+1, l-1)
   return 
for i in range(0, n):
   f=input().split()
   d[i]=f[1:len(f)]
for i in d[0]:
   words.append(i)
   worder(i, 1, l-1)
words.sort()
for i in words: print(i)