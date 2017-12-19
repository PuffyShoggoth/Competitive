h=int(input())
d={}
for i in range(0, h):
    a=input().split()
    b=int(a[0])
    f=1
    for k in range(1, b+1):
        f=f*int(a[k])
    d[f]=i+1
for i in range(0, 3):
    l=(d[max(d)])
    del d[(max(d))]
    print(l)
