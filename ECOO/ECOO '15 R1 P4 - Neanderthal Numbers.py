lw=["ook", "ookook", "oog", "ooga", "ug", "mook", "mookmook", "oogam", "oogum", "ugug"]
def numbers(k):
   t=0
   if dp[k]!=-1: return dp[k]
   for i in lw:
      if k+len(i)==len(w) and w[k:len(w)]==i:
         t+=1
      elif k+len(i)<len(w) and w[k:k+len(i)]==i:
         t+=numbers(k+len(i))
   dp[k]=t
   return t

for i in range(10):
   w=input()
   dp=[-1]*len(w)
   print(numbers(0))