h=input()
l=[int(x) for x in h]
l.sort()
if sum(l)%3==0 and 0 in l and len(l)>1:
   for i in l[::-1]: print(i, end="")
else: print(-1)