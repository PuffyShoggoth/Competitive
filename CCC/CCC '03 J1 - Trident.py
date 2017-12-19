t=int(input())
s=int(input())
h=int(input())
for top in range(0,t):
   print('*'+' '*s+'*'+' '*s+'*')
print('*'*(s*2+3))
for bot in range(0,h):
   print(' '*(s+1)+'*')