na=int(input())
nb=int(input())
bc=int(input())
bd=int(input())
k=int(input())

def steps(x, y, l):
  bcount=0
  bd='UP'
  b=0
  for i in range(0, l):
     if bd=='UP':
         b=b+1
         bcount=bcount+1
         if bcount==x:
            bd='DOWN'
            bcount=0
     else:
        b=b-1
        bcount=bcount+1
        if bcount==y:
            bd='UP'
            bcount=0
  return b  
                    

n=steps(na, nb, k)
b=steps(bc, bd, k)


    
if n==b: print('Tied')
elif n>b: print('Nikky')
else: print('Byron')