p=int(input())
r=''
d={2:['A', 'B', 'C'], 3:['D', 'E', 'F'], 4:['G', 'H', 'I'], 5:['J', 'K', 'L'], 6:['M', 'N', 'O'], 7:['P', 'Q', 'R', 'S'], 8:['T', 'U', 'V'], 9:['W', 'X', 'Y', 'Z']}
for i in range(0, p):
   j=input()
   j=j.replace('-', '')
   for k in range(0,10):
      if j[k].isdigit():
         r=r+j[k]
      else:
         for y in range(2, 10):
            if j[k] in d[y]: r=r+str(y)
   print(r[0:3]+'-'+r[3:6]+'-'+r[6:10])
   r=''