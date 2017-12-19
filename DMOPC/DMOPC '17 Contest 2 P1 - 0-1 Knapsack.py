n = int(input())
tt = 0
for i in range(n):
   c, v = map(int, input().split())
   if v>0: tt+=c
print(tt)