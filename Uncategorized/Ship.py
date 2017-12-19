h=['B', 'F', 'T', 'L', 'C']
i=input()
for k in range(0, len(i)):
   if i[k] in h: h.remove(i[k])
for j in range(0, len(h)):
   print(h[j])
if len(h)==0: print('NO MISSING PARTS')