n=int(input())
for i in range(0, n):
   q=input()
   q=q.split()
   h=[int(x) for x in q]
   if h[3]<=(h[0]-h[1]) and h[3]>=(h[0]-h[2]): print("Yes")
   else: print("No")