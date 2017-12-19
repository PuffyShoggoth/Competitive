Cthulhu=int(input())
g=float(0)
for i in range(0, Cthulhu):
    H=input().split()
    if float(H[1])>g:
        g=float(H[1])
        m=H[0]
print(m)