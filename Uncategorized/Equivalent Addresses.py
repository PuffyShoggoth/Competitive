n=input()
t=int(n[0:4], 16)+int(n[5:8], 16)
if t<4095: t+=65536
f=n[8]
for i in range(0, 4096):
   k="%04.0X"%(t-i)
   print(k[len(k)-4:len(k)]+":"+"%03.0X"%(i)+f)