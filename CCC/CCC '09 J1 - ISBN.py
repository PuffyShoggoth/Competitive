h='9780921418'
for i in range(0, 3):
   h=h+input()
s=0
for i in range(0, len(h)-1, 2):
   s=s+int(h[i])*1+int(h[i+1])*3
print('The 1-3-sum is', s+int(h[len(h)-1]))