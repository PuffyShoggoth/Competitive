h=int(input())
fiebs=[1, 1]+[0]*(h-2)
a, b=1, 1
for i in range(0, h-2):
   a, b=b, a+b
   if b>(h): break
   fiebs[b-1]=1
l=True
grell=input()
for i in range(h):
   if fiebs[i]==0 and grell[i]!="A": continue
   elif fiebs[i]==1 and grell[i]=="A": continue
   else:
      l=False
      break
if l==True: print("That's quite the observation!")
else: print("Bruno, GO TO SLEEP")