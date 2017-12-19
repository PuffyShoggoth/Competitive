d1 = {2:["a", "b", "c"], 3:["d","e","f"], 4:["g", "h", "i"], 5:["j", "k", "l"], 6:["m", "n", "o"], 7:["p", "q", "r", "s"], 8:["t", "u", "v"], 9:["w", "x", "y", "z"]}
d ={}
l = [int(i) for i in input().split()]
for i in range(0, 9):
   if l[i] == 1: continue
   else:
      for j in range(0, len(d1[l[i]])):
         d[d1[l[i]][j]] = tuple([i+1, j+1])
s = input()
pv = 0
for i in s:
   if d[i][0] == pv: print("#", end="")
   pv = d[i][0]
   for j in range(d[i][1]):
      print(d[i][0],end="")