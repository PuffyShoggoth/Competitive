n=int(input())
k={}
for i in range(0, n):
   l=input().split()
   k[l[1]]=l[0]
s=input()
ind=0
for i in range(1, len(s)+1):
   if s[ind:i] in k:
      print(k[s[ind:i]], end="")
      ind=i