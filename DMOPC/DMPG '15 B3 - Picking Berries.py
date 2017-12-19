h=input().split()
j=int(h[1])
b=0
for a in range(0, j):
    k=input()
    b=b+k.count('o')
    l=k.replace('o', ' ')
    l=l.replace('*', ' ')
    print(l)
print(b*'o')