a=int(input())
def end(x):
   s=''
   u=['a', 'e', 'i', 'o', 'u']
   x=x.lower()
   for i in range(len(x)-1, -1, -1):
      s=s+x[i]
      if x[i] in u: break
   return s
for i in range(0, a):
      k=input().split()
      k=k[len(k)-1]
      k=end(k)
      l=input().split()
      l=l[len(l)-1]
      l=end(l)
      m=input().split()
      m=m[len(m)-1]
      m=end(m)
      n=input().split()
      n=n[len(n)-1]
      n=end(n)
      if k==l and k==m and k==n and l==m and l==n and n==m:
       print('perfect')
      elif k==l and m==n:
       print('even')
      elif k==m and l==n:
       print('cross')
      elif k==n and l==m:
       print('shell')
      else:
       print('free')