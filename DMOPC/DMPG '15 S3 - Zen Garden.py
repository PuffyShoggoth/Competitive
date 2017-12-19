n=int(input())
l=[int(i) for i in input().split()]
f=sum(l)
m=int(input())
for i in range(m):
   a, v=map(int, input().split())
   f-=min(v, l[a], l[a-1])
print(f)