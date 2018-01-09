l = [int(x) for x in input().split()]
l.sort()
print(min(l[:2])*min(l[2:]))