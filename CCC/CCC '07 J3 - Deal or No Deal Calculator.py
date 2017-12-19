l=[100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000]
h=int(input())
q=0
k=0
for i in range(0, h):
   r=int(input())
   del l[r-1]
   l.insert(r-1, 0)
   k=k+1
for i in range(0, len(l)):
    q=q+l[i]
q=q//(10-k)
if q>int(input()):
    print('no deal')
else: print('deal')