import math
n=int(input())
h=0
while True:
  if n==2:
      print(2)
      break
  else:
      for i in range(2, int(math.sqrt(n))+1):
        if n%i==0:
          break
        if i==int(math.sqrt(n)) and h!=5:
            h=5
            print(n)
            break
  if h==5: break
  n=n+1
  h=0