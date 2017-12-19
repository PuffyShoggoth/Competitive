trout=int(input())
pike=int(input())
pickerel=int(input()) 
lake=int(input())
combos=0
for a in range(0, lake+1):
   for b in range(0, lake+1):
      for c in range(0, lake+1):
          if a+b+c==0: continue
          if a*trout+b*pike+c*pickerel<=lake:
              print(a,'Brown Trout,', b, 'Northern Pike,', c, 'Yellow Pickerel')
              combos=combos+1
print('Number of ways to catch fish:', combos)