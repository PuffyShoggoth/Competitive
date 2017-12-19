h=int(input())
for i in range(0, h):
      year, month, day=map(int, input().split())
      if 2007-year>18: print('Yes')
      elif 2007-year==18 and month<2: print('Yes')
      elif 2007-year==18 and month==2 and 27>=day: print('Yes')
      else: print('No')