x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
xs, ys = map(int, input().split())
d = int(input())
if (x1-xs)**2+(y1-ys)**2 <= d**2 or (x2-xs)**2+(y2-ys)**2 <= d**2:
   print("Yes")
else:
   print("No")