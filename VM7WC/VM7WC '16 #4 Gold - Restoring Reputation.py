D, I, R=map(int, input().split())
words=input().split()
if len(words)!=2:
   b=words[0]
   a=input()
else: 
   b=words[0] 
   a=words[1]
d={}
def match(st, end, wrd, D, I, R):
   if wrd==" ": return I*(len(a)-end)
   if tuple([st, end]) in d: return d[tuple([st, end])]
   m=-1
   for i in range(0, min(len(wrd), len(a)-st)):
      if wrd[i]!=a[i+st]: 
         m=i
         break
   if m<0: 
      if st+len(wrd)>len(a):
         d[tuple([st, end])]=(st+len(wrd)-len(a))*D
         return (st+len(wrd)-len(a))*D
      elif st+len(wrd)==len(a):
         d[tuple([st, end])]=0
         return 0
      else: 
         d[tuple([st, end])]=(len(a)-st-len(wrd))*I
         return (len(a)-st-len(wrd))*I
   else: 
      k=match(st+m, end-1, wrd[m+1:len(wrd)], D, I, R)+D
      k=min(k, match(st+1+m, end+1, wrd[m:], D, I, R)+I)
      k=min(k, match(st+1+m, end, wrd[1+m:len(wrd)], D, I, R)+R)
      d[tuple([st, end])]=k
      return k
print(match(0, len(b), b, D, I, R))