n=int(input())
c=float(input())
f=0.00
for i in range(n):
   f+=float(input())
if f>round(c, 2): print("Fardin's broke")
elif round(c-f, 2)==0.0: print("0.00")
else: print(round(c-f, 2))