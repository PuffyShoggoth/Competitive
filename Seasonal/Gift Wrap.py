n=int(input())
if n%2==0: k=1
else: k=0
l=chr(ord('a')+n)*(n*2-1)
ls=[]
for i in range(n-1):
   l=l[0:i]+chr(ord(l[i])-1)*(n*2-1-i*2)+l[len(l)-i:len(l)]
   ls.append(l)
for i in ls:
   print(i)
print(l[0:n-1]+"a"+l[n:len(l)])
ls.reverse()
for i in ls:
   print(i)