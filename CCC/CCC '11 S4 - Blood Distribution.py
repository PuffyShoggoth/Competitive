blood=input().split()
patients=input().split()
def served(x, y):
   if int(blood[x])<int(patients[y]):
      h=int(blood[x])
      blood[x]=0
      patients[y]=int(patients[y])-h
   else: 
      blood[x]=int(blood[x])-int(patients[y])
      h=int(patients[y])
      patients[y]=0
   return h
def bloodp(x, y): 
   t=served(x+1, y+1)
   u=served(x, y+1)
   return (t+u)
def oserved(x):
   return served(0, x)+ bloodp(0, x)
def aserved(x):
   return served(2, x)+ bloodp(2, x)
def bserved(x):
   return served(4, x)+ bloodp(4, x)
def abserved(x):
   return served(6, x)+bloodp(6, x)+aserved(x)+bserved(x)+oserved(x)
print(oserved(0)+aserved(2)+oserved(2)+bserved(4)+oserved(4)+abserved(6))