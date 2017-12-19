P=int(input())
Q=int(input())
W=int(input())
for i in range(0, 101):
   h=(P/(100))*(100-W)+(i/100)*W
   if h-int(h)>=0.5: h=int(h)+1
   else: h=int(h)
   if h==Q:
       print(i)
       break
if h!=Q: print('DROP THE COURSE')