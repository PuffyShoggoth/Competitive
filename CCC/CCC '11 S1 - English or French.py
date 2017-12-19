Cthulhu=int(input())
E=0
F=0
for i in range(0, Cthulhu):
   s=str(input())
   T=s.count('T')+s.count('t')
   S=s.count('S')+s.count('s')
   if T>S: E=E+1
   elif S>T: F=F+1
if E>F: print('English')
if F>E: print('French')
if E==F: print('French')