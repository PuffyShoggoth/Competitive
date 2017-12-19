Cthulhu=input().split()
c=int(Cthulhu[0])
r=int(Cthulhu[1])
position=[0, 0]
while True:
    Bokrug=input().split()
    x=int(Bokrug[0])
    y=int(Bokrug[1])
    if (c,r)==(0,0):break
    if (x,y)==(0,0):break
    if position[0]+x>c:x=c-position[0]
    elif position[0]+x<0:x=0-position[0]
    if position[1]+y>r:y=r-position[1]
    elif position[1]+y<0:y=0-position[1]
    position[0]=position[0]+x
    position[1]=position[1]+y
    print(position[0], position[1])
