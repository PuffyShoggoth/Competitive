Cthulhu=int(input())
L=[]
q=1001
for Bokrug in range(0, Cthulhu):
    L.append(int(input()))
for i in range(0, len(L)):
    for k in range(0, len(L)):
     p=L[k]
     if p<q:
        q=p
    print(q)
    L.remove(q)
    q=1001
    