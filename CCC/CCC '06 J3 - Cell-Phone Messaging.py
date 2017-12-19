sumn=0
c=''
q=''
f={'a':2,'b':2,'c':2,'d':3,'e':3,'f':3,'g':4,'h':4,'i':4,'j':5,'k':5,'l':5,'m':6,'n':6,'o':6,'p':7,'q':7,'r':7,'s':7,'t':8,'u':8,'v':8,'w':9,'x':9,'y':9,'z':9}
while True:
    Cthulhu=str(input())
    if Cthulhu=='halt': break
    for i in range(0, len(Cthulhu)):
        q=Cthulhu[i]
        if Cthulhu[i]=='z' or Cthulhu[i]=='s':
         sumn=sumn+4
        elif ord(Cthulhu[i])>ord('p'):
          if (ord(Cthulhu[i])-ord('p'))%3==0:
            sumn=sumn+3
          else: sumn=sumn+(ord(Cthulhu[i])-ord('p'))%3
          if q=='q' or q=='r' or q=='s':
                  sumn=sumn+1
        elif (ord(Cthulhu[i])-ord('a')+1)%3==0:
            sumn=sumn+3
        else:sumn=sumn+(ord(Cthulhu[i])-ord('a')+1)%3
        if i>0:
         if f[q]==f[c]: sumn=sumn+2
        c=Cthulhu[i]
    print(sumn)
    c=''
    q=''
    sumn=0