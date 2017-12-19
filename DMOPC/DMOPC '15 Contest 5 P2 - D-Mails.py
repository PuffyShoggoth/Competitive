n=int(input())
ln=["elpsycongroo", "tuturu", "superhacker", "myfork"]
d=["Okabe", "Mayuri", "Daru", "Kurisu"]
for i in range(n):
   k=input()
   t=[]
   for oo in range(0, 4):
      p=ln[oo]
      e=0
      for q in range(0, len(k)):
          if e>len(p)-1: break
          if k[q]==p[e]: e+=1
      if e==len(p): t.append(oo)
   if len(t)==1: print(d[t[0]])
   elif len(t)==0: print("SERN spy!")
   else:
      for i in t[0:len(t)-1]:
         print(d[i], "or", end=" ")
      print(d[t[len(t)-1]])