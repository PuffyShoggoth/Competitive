t=int(input())
g=0
for i in range(t):
   g+=float(input())
   g=g%360
print(format(round(g, 5), ".5f"))