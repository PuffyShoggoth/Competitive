number=int(input())
for allcensor in range(0, number):
   Azathoth=''
   Cthulhu=input().split()
   for linecensor in range(0, len(Cthulhu)):
      if len(Cthulhu[linecensor])==4: Cthulhu[linecensor]='****'
   for restorespaces in range(0, len(Cthulhu)):
     Azathoth=Azathoth+Cthulhu[restorespaces]+' '
   print(Azathoth)