d={}
a=['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', '-', '.', 'e']
c=0
for i in range(0, 5):
   for k in range(0, 6):
      d[a[c]]=tuple([k, i])
      c+=1
paq=input()+"e"
moves=0
burf=d["A"]
borf=d[paq[0]]
for i in range(1, len(paq)+1):
   moves+=max(burf[0], borf[0])-min(burf[0], borf[0])+max(burf[1], borf[1])-min(burf[1], borf[1])
   
   if i==len(paq): break
   burf=borf
   borf=d[paq[i]]
print(moves)