lc, rc, w=map(int, input().split())
l=[int(x) for x in input().split()]
r=[int(x) for x in input().split()]
l.sort()
l.reverse()
r.sort()
r.reverse()
moves=0
while sum(l) or sum(r):
   if sum(l)>sum(r): hvy, lgt=l, r
   else: hvy, lgt=r, l
   for p in hvy:
         if sum(lgt)-sum(hvy)+p<=w:
            hvy[hvy.index(p)]=0
   moves+=1
print(moves)