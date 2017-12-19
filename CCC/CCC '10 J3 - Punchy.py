a=0
b=0
i=input().split()
c=int(i[0])
while c!=7:
   if c==1:
      if i[1]=="A": a=int(i[2])
      else: b=int(i[2])
   elif c==2:
      if i[1]=="A": print(a)
      else: print(b)
   elif c==3:
      if i[1]=="A": 
         if i[2]=="B":
            a=a+b
         else: a=a+a 
      else: 
         if i[2]=="B":
            b=b+b
         else: b=a+b
   elif c==4: 
      if i[1]=="A": 
         if i[2]=="B":
            a=a*b
         else: a=a*a 
      else: 
         if i[2]=="B":
            b=b*b
         else: b=a*b
   elif c==5: 
      if i[1]=="A": 
         if i[2]=="B":
            a=a-b
         else: a=a-a 
      else: 
         if i[2]=="B":
            b=b-b
         else: b=b-a
   elif c==6: 
      if i[1]=="A": 
         if i[2]=="B":
            a=a//b
         else: a=a//a 
      else: 
         if i[2]=="B":
            b=b//b
         else: b=b//a
   i=input().split()
   c=int(i[0])