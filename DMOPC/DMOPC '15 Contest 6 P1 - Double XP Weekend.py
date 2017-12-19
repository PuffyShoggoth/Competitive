ce=int(input())
de=int(input())
be=int(input())
e=int(input())
c=int(input())
de-=ce
if (de/(e*3))<=(be/e):
   print((de//(e*3)+(de%(e*3)!=0)))
   print(c*((de//(e*3)+(de%(e*3)!=0))))
else:
   de-=((be//e)*3)*e
   ftc=(be//e)
   if be%e!=0:
      de-=be%e+e*2
      ftc+=1
   ftc+=de//(e*2)+(de%(e*2)!=0)
   print(ftc)
   print(ftc*c)