n, k, i = map(int, input().split())
def pr(st, ed):
   vl=1
   for i in range(st, ed+1): vl*=i
   return vl
if k>2:
   l=[[1]]
   for q in range(1, n):
      l.append([l[q-1][0]*((k+q+1)//(q+1)*q+max(0, k%(q+1)-1))/(q+1+k)])
      for r in range(1, q):
         l[q].append(l[q-1][r-1]*((k+q+1)//(q+1)*(r)+min(r,k%(q+1)))/(q+1+k)+l[q-1][r]*((k+q+1)//(q+1)*(q-r)+max(0, k%(q+1)-r-1))/(q+1+k))
      l[q].append(l[q-1][q-1]*((k+q+1)//(q+1)*q+k%(q+1))/(q+1+k))
   print(l[-1][i-1])
elif k==2:
   j = n-i
   tt = 0
   cv = pr(i-1, i-1+k)*2/pr(n-1, n+k)
   tt = cv
   for l in range(1, j+1):
      cv = cv*(j-l+1)/(n-1-l)
      tt+= cv*(l+1)
   print(tt)
else:
   print(pr(i, i-1+k)*(1+k)/pr(n, n+k))