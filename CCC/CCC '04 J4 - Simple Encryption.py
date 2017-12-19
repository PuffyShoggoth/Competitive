keyword=input()
withsymbols=input()
tocode=''
for i in range(0, len(withsymbols)):
   if withsymbols[i].isalpha():
      tocode=tocode+withsymbols[i]
c={}
def lettershift(x, y):
   if ord(x)+ord(y)-ord('A')>ord('Z'): return chr((ord(x)+ord(y))-ord('Z')-1)
   else: return chr(ord(x)+ord(y)-ord('A'))
for i in range(0, len(keyword)):
   for q in range(i, len(tocode), len(keyword)):
      c[q]=lettershift(tocode[q], keyword[i])
coded=''
for i in range(0, len(c)):
   coded=coded+c[i]
print(coded)