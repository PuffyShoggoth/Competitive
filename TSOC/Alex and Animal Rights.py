r, c=map(int, input().split())
m=[]
fl={}
for i in range(0, r):
   for w in range(0, c):
    fl[tuple([i, w])]=1
for i in range(0, r):
  m.append(input())
tm=0
def s(rif, cif):
   q=[tuple([rif, cif])]
   rm=0
   while q:
      f=q.pop()
      ri=f[0]
      ci=f[1]
      if m[ri][ci]=="M": 
         rm=1
      if ri>0 and m[ri-1][ci]!="#" and fl[tuple([ri-1, ci])]:
         fl[tuple([ri-1, ci])]=0
         q.append(tuple([ri-1, ci]))
      if ri<r-1 and m[ri+1][ci]!="#" and fl[tuple([ri+1, ci])]:
         fl[tuple([ri+1, ci])]=0
         q.append(tuple([ri+1, ci]))
      if ci>0 and m[ri][ci-1]!="#" and fl[tuple([ri, ci-1])]:
         fl[tuple([ri, ci-1])]=0
         q.append(tuple([ri, ci-1]))
      if ci<c-1 and m[ri][ci+1]!="#" and fl[tuple([ri, ci+1])]:
         fl[tuple([ri, ci+1])]=0
         q.append(tuple([ri, ci+1]))
   return rm
for i in range(0, r):
   for k in range(0, c):
      if m[i][k]!="#" and fl[tuple([i, k])]:
         fl[tuple([i, k])]=0
         tm+=s(i, k)
print(tm)