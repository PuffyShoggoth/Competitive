h=input()
l=[]
def bana(x):
   return str(eval(x))
h=h.replace("^", "**").split()
for i in range(0, len(h)):
   if h[i].isnumeric()==True:
      l.append(h[i])
   else: 
      l[len(l)-2]=bana(l[len(l)-2]+ h[i]+ l[len(l)-1])
      del l[len(l)-1]
print(round(float(l[0]), 1))