import sys
def gencycle(x):
   p=[]
   for i in range(0, len(x)-1):
      p.append(int(x[i+1])-int(x[i]))
   return p
def repetitions(x):
   for i in range(1, len(x)+1):
      if x[0:i]*(len(x)//i)+x[0:len(x)%i]==x:
           orp=i
           break
   return orp
while True:
 m=sys.stdin.readline().split()
 if m[0]=='0': break
 if len(m)==2: print(0)
 else: 
    o=(gencycle(m[1:]))
    print(repetitions(o))