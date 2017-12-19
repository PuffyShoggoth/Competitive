n = int(input())
l = [int(i) for i in input().split()]
tt = 0
for i in range(n): 
    if i%2 == l[i]%2: tt+=1
print(tt)