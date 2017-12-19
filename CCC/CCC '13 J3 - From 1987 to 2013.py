def dig(X):
   F=str(X)
   L=[]
   for h in range(0, len(F)):
     L.append(F[h])
   for same in range(0, len(L)):
      if L.count(L[same])==1:
        continue
      else: return False
   return True
year=int(input())+1
if year==0: print(1)
while dig(year)==False:
   year=year+1
print(year)