n=int(input())
l=[bin(int(input(), base=16)) for i in range(n)]
def pad(x):
   x=(10-len(x))*"0"+x[2:len(x)]
   return x
def con(x):
   x=x.upper()
   return pad(x)
for i in l: 
   if len(i)<23 or i[len(i)-21]=="1": print(con(hex(int(i, base=2)-2**20)), con(hex(int(i, base=2))))
   else: print(con(hex(int(i, base=2))))