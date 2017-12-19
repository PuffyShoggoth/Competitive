k=int(input())
h=[int(i) for i in input().split()]
q=[]
for l in range(0, k):
   if h[l] not in q: q.append(h[l])
print(len(q))