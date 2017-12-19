n=int(input())
p=[]
print("On the 1st day of Christmas my true love sent to me:")
h=input()
print("1", h)
p.append("and 1 "+h)
for i in range(2, n+1):
   print()
   if i%100==11 or i%100==12 or i%100==13: h=str(i)+"th"
   elif i%10==1: h=str(i)+"st"
   elif i%10==2: h=str(i)+"nd"
   elif i%10==3: h=str(i)+"rd"
   else: h=str(i)+"th"
   print("On the", h, "day of Christmas my true love sent to me:")
   p.append(str(i)+" "+input())
   for koo in range(len(p)-1, -1, -1):
      print(p[koo])