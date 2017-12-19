w=int(input())
x=int(input())
y=int(input())
z=int(input())
if w>x and x>y and y>z:
    print('Fish Diving')
elif z>y and y>x and x>w:
    print('Fish Rising')
elif w==x and x==y and y==z:
    print('Fish At Constant Depth')
else:
    print('No Fish')
