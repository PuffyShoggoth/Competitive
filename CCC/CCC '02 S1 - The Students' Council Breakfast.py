pink=int(input())
green=int(input())
red=int(input()) 
orange=int(input())
prof=int(input())
combos=0
mintic=prof
for a in range(0, prof+1):
   for b in range(0, prof+1):
      for c in range(0, prof+1):
         for d in range(0, prof+1):
            if a*pink+b*green+c*red+d*orange==prof:
               print('# of PINK is', a, '# of GREEN is', b, '# of RED is', c, '# of ORANGE is', d)
               combos=combos+1
               if a+b+c+d<mintic: mintic=a+b+c+d
print('Total combinations is', str(combos)+'.')
print('Minimum number of tickets to print is', str(mintic)+'.')