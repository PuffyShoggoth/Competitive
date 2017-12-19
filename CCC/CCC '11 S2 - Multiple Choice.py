p=int(input())
correct=0
la=[]
for i in range(0, p):
   a=input()
   b=input()
   la.extend([a, b])
for i in range(0, p):
   if la[i]==la[i+p]:
      correct=correct+1
print(correct)