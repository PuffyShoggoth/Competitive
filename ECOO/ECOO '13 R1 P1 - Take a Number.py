import sys
h=int(input())
i=0
k=0
while True:
    
    j=input()
    if j=='TAKE': 
         i=i+1
         if h==999: h=1
         else:h=h+1
    elif j=='SERVE': k=k+1
    
    if j=='CLOSE':
        print(i, i-k, h)
        i, k= 0, 0
    elif j=='EOF': break