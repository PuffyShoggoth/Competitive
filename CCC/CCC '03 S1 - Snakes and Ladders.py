place=1
oldplace=1
snakes={54:19, 90:48, 99:77}
ladders={9:34, 40:64, 67:86}
while True:
   newroll=int(input())
   if newroll==0: 
      print('You Quit!')
      break
   else:
      place=place+newroll
      if place in snakes:
         place=snakes[place]
      if place in ladders:
         place=ladders[place]
      if place>100:
         place=oldplace
      print('You are now on square', place)
      if place==100:
         print('You Win!')
         break
      oldplace=place