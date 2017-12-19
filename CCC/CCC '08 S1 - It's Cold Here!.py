tempsdict={}
tempslist=[]
while True:
   tot=input().split()
   city=tot[0]
   temp=tot[1]

   tempsdict[tuple([int(temp)])]=city
   tempslist.append(int(temp))
   if city=='Waterloo': break

print(tempsdict[tuple([min(tempslist)])])