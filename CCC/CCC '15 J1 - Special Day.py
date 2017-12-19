x=int(input())
y=int(input())
if x<2:
    print('Before')
elif x==2 and y<18:
    print('Before')
elif x==2 and y==18:
    print('Special')
else:
    print('After')
