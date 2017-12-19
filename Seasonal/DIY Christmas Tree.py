n=int(input())
adjl=[False]
import sys
for i in range(0, n):
    adjl.append(tuple([int (x) for x in sys.stdin.readline().split()]))
def maketree(node, numb):
    if adjl[node]==False: return False
    if adjl[node][0]==0:
        adjl[node]=False
        return [numb]
    temp=[]
    q=adjl[node][1:len(adjl[node])][:]
    adjl[node]=False
    for i in q:
        k=maketree(i, numb-len(temp))
        if k!=False: temp=temp+k
        else: return False
    return [numb-len(temp)]+temp
g=maketree(1, n)
if g==False or len(g)!=n: print(0)
else:
    for i in g: print(i, end=" ")