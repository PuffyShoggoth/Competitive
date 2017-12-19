rounds=int(input())
A=100
D=100
for i in range(0, rounds):
   Cthulhu=str(input()).split()
   RA=int(Cthulhu[0])
   RD=int(Cthulhu[1])
   if RA>RD:
      D=D-RA
   elif RD>RA:
      A=A-RD
print(A)
print(D)