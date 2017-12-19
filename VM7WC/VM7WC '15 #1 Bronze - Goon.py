def sm(x):
   total=0
   for i in x: total+=int(i)
   return total
l=[sm(x) for x in input().split("-")]
if l[0]==l[1] and l[1]==l[2]: print("Goony!")
else: print("Pick up the phone!")