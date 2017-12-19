h=(int(input())%26)*-1
s=input()
uncoded=''
def lettershift(x):
   if ord('a')<=ord(x)<=ord('z'):
      if ord(x)+h>ord('z'): return chr(ord('a')+ord(x)+h-1-ord('z'))
      elif ord(x)+h<ord('a'): return chr(ord('z')-(ord('a')-(ord(x)+h+1)))
      else: return chr(ord(x)+h)
   elif ord('A')<=ord(x)<=ord('Z'):
      if ord(x)+h>ord('Z'): return chr(ord('A')+ord(x)+h-1-ord('Z'))
      elif ord(x)+h<ord('A'): return chr(ord('Z')-(ord('A')-(ord(x)+h+1)))
      else: return chr(ord(x)+h)
for i in range(0, len(s)):
   if s[i]==' ': uncoded=uncoded+' '
   else: uncoded=uncoded+lettershift(s[i])
print(uncoded)