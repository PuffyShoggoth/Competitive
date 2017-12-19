h=int(str(int(str(int(str(input()))))))
w=str(str(str(input())))
def pal(x, y):
   p=min(x+1, h-y)
   for oop in range(0, p):
      if w[x-oop]!=w[y+oop]: 
         return w[x-oop+1:y+oop]
   return w[x-p+1:y+p]
bst=""
for i in range(0, h):
   temp=pal(i, i)
   if len(temp)>len(bst): bst=temp
   if i<h-1: temp=pal(i, i+1)
   if len(temp)>len(bst): bst=temp
print(bst)
print(len(bst))