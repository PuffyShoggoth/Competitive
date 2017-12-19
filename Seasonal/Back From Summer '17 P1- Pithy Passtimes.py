n = int(input())
l = input().split()
cnt = 0
for i in l: 
   if len(i) <= 10: cnt+=1
print(cnt)