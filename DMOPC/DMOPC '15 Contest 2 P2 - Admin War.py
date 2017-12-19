h=int(input())
xy=input().split()
fa=input().split()
xye=0
fatal=0
for i in range(0, h):
   if int(xy[i])>int(fa[i]): xye=xye+1
   elif int(xy[i])<int(fa[i]): fatal=fatal+1
print(xye, fatal)
if xye>fatal: print("Xyene")
elif fatal>xye: print("FatalEagle")
else: print("Tie")