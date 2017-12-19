K=int(input())
code=str(input())
H=''
def shift(X, Y):
   if ord(X)+Y<ord('A'): return chr(ord(X)+Y+26)
   else: return chr(ord(X)+Y)
for l in range(0, len(code)):
    H=H+(shift(code[l], -(3*(l+1)+K)))
print(H)