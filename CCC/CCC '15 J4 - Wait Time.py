h=int(input())
r=[]
ft={}
for i in range(0, h):
    ui=input().split()
    o=ui[0]
    f=int(ui[1])
    for i in r:
        if o=='W': ft[i]=ft[i]+f-1
        else: ft[i]=ft[i]+1
    if o=='S':
        r.remove(f)
    elif o=='R':
        r.append(f)
        if f not in ft: ft[f]=0
for i in r:
   ft[i]=-1
l=[]
for i in ft:
    l.append(i)
l.sort()
for i in l:
   print(i, ft[i])