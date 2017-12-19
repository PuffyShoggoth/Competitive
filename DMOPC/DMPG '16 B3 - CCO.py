fl=input()
sl=input()
tl=input()
f=input().split()
v=f[0]
h, w=map(int, f[1:3])
print("="*(w*2+5))
print("|"+v+" "*(w*2+3-len(v))+"|")
for i in range(1, h):
   print("|"+" "*(w*2+3)+"|")
print("|"+" "*w+fl+" "*w+"|")
print("|"+" "*w+sl+" "*w+"|")
print("|"+" "*w+tl+" "*w+"|")
for i in range(1, h):
   print("|"+" "*(w*2+3)+"|")
print("|"+" "*(w*2+3-len(v))+v+"|")
print("="*(w*2+5))