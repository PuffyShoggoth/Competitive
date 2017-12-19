n=input()
n=n[::-1]
m=input()
m=m[::-1]
nn=""
nm=""
for i in range(0, min(len(m), len(n))):
        if n[i]>m[i]:
               nn+=n[i]
        elif m[i]>n[i]:
               nm+=m[i]
        else:
               nn+=n[i]
               nm+=m[i]
if len(m)>len(n):
   nm+=m[len(n):]
elif len(n)>len(m):
   nn+=n[len(m):]
for i in nn, nm:
  if len(i)>0:
    print(int(i[::-1]))
  else: print("YODA")