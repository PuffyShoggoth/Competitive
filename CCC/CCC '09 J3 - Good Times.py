def switchtime(x, y):
   return ((x//100+y//100)+(x%100+y%100)//60)%24*100+(x%100+y%100)%60
x=int(input())
times={0:['Ottawa', 0], 1:['Victoria', -300], 2:['Edmonton', -200], 3:['Winnipeg', -100], 4:['Toronto', 0], 5:['Halifax', 100], 6:['St. John\'s', 130]}
for i in range(0, 7):
   print(switchtime(x, times[i][1]), 'in', times[i][0])