f=int(input())
l=int(input())
fl=[]
ll=[]
for i in range(0, f):
   fl.append(input())
for i in range(0, l):
   ll.append(input())
for i in range(0, f):
   for h in range(0, l):
      print(fl[i], 'as', ll[h])