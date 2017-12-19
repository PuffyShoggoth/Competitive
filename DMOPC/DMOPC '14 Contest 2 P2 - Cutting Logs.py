l=int(input())
lg=input().split("X")
print(len(lg)-lg.count(''))
for i in lg: 
   if i!='': print(i)