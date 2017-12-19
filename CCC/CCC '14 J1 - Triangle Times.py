x=int(input())
y=int(input())
z=int(input())
if x+y+z==180:
    if x==y and y==z:
        print('Equilateral')
    elif x==y or y==z or x==z:
        print('Isosceles')
    else:
        print('Scalene')
else: print('Error')
