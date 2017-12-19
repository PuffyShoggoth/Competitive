dm=[0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
ts=int(input())
cd=input().split()
y=int(cd[0][0:4])-2009
m=int(cd[0][5:7])
d=int(cd[0][8:10])
h=int(cd[1][0:2])
toth=((y)*365+sum(dm[0:m])+d)*24+h-24
toth-=ts
y=str((toth//(365*24))+2009)
toth=toth%(24*365)
m="0"
for i in range(1, 13):
   if sum(dm[1:i])*24<=toth:m=str(i)
toth-=sum(dm[1:int(m)])*24
d=str(toth//24+1)
toth=toth%24
h=str(toth)
print(y+"/"+"0"*(2-len(m))+m+"/"+"0"*(2-len(d))+d, "0"*(2-len(h))+h+cd[1][2:8])