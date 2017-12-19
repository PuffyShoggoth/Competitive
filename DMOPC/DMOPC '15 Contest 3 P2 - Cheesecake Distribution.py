fr=int(input())
l=[int(i) for i in input().split()]
if sum(l)%fr!=0: print("Impossible")
else: 
   h=sum(l)//fr
   totmin=0
   for i in range(0, fr):
      if l[i]>h: totmin=totmin+(l[i]-h)
   print(totmin)