h, m=map(int, input().split())
t=int(input())
h+=(t//60)
m+=(t%60)
h+=m//60
h=h%24
m=m%60
print(h, m)