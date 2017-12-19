import sys
h=int(input())
def sort(t, a):
   b=a
   while t:
      if a+1==t[0]: 
         a=t.pop(0)
         continue
      if a+1==t[len(t)-1]: 
         a=t.pop()
         continue
      if b-1==t[0]: 
         b=t.pop(0)
         continue
      if b-1==t[len(t)-1]: 
         b=t.pop()
         continue
      break
   return not bool(t)
for i in range(1, h+1):
   p=int(sys.stdin.readline())
   l=[int(i) for i in sys.stdin.readline().split()]
   oo=l[:]
   if sort(oo, oo.pop(0)):
      print("Case #"+str(i)+": yes")
   elif sort(l, l.pop()):
      print("Case #"+str(i)+": yes") 
   else:
      print("Case #"+str(i)+": no")