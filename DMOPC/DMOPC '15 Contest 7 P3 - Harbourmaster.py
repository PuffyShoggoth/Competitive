at=[int(x) for x in input().split()]
n=int(input())
cm=[[int(x) for x in input().split()] for i in range(n)]
a=[0, 0, 0]
t=0
if n<=5: 
   for i in range(0, n):
      for k in range(0, 3):
         a[k]+=cm[i][k]
   for i in range(0, 3):
      a[i]=a[i]/at[i]
   t=min(a)
else:
 for i in range(0, n):
   for j in range(i+1, n):
      for k in range(j+1, n):
         for l in range(k+1, n):
            for m in range(l+1, n):
               for q in range(0, 3):
                  a[q]=(cm[i][q]+cm[j][q]+cm[k][q]+cm[l][q]+cm[m][q])/at[q]
               t=max(t, min(a))
print(min(100.0, round(t*100, 1)))