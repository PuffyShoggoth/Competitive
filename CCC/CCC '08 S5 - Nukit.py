a=[tuple([2, 1, 0, 2]), tuple([1, 1, 1, 1]), tuple([0, 0, 2, 1]), tuple([0, 3, 0, 0]), tuple([1, 0, 0, 1])]
d={}
def thinginator(l, i):
    s=l[0]-a[i][0]
    t=l[1]-a[i][1]
    u=l[2]-a[i][2]
    v=l[3]-a[i][3]
    return [bool(s>=0 and t>=0 and u>=0 and v>=0), tuple([s, t, u, v])]
def nuke(r):
    if r in d:
        return not d[r]
    else:
        d[r]=False
        for k in range(0, 5):
            temp=thinginator(r, k)
            if temp[0]:
                d[r]=nuke(temp[1])
            if d[r]==True:
                return not d[r]
    return not d[r]
h=int(input())
for butt in range(0, h):
    if nuke(tuple([int(x) for x in input().split()]))==False: print("Patrick")
    else: print("Roland")