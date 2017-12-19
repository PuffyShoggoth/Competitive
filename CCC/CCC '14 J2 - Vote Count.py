votes=int(input())
singervotes=str(input())
A=0
B=0
for votespersinger in range(0, votes):
    if singervotes[votespersinger]=='A':
        A=A+1
    else: B=B+1
if A==B:
    print('Tie')
elif A>B:
    print('A')
else: print('B')