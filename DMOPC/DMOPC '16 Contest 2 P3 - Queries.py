t = int(input())
for i in range(t):
   n, m = map(int, input().split())
   mx=0
   my=0
   for j in range(m):
      a, b = map(int, input().split())
      mx=max(mx, a)
      my= max(my, b)
   if (mx+my)>n: print("-1")
   else:
      print("a"*mx+"b"*my+"a"*(n-(mx+my)))
#Subsequence, not contiguous subsequence... $#%@!