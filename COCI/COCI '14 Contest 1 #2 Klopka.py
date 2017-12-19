h=int(input())
my=0
mx=0
miy=105
mix=105
for i in range(0, h):
   p=[int(x) for x in input().split()]
   mx=max(mx, p[0])
   my=max(my, p[1])
   mix=min(mix, p[0])
   miy=min(miy, p[1])
print(max(mx-mix, my-miy)**2)