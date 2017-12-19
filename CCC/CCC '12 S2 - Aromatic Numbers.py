number=input()
rn={'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
p=rn[number[len(number)-1]]
Tar=0
for i in range(len(number)-1, -1, -2):
    
    AR=int(number[i-1])*rn[number[i]]
    if rn[number[i]]<p:
        Tar=Tar-AR
    else:
        Tar=Tar+AR
    p=rn[number[i]]
print(Tar)