h=int(input())
i=int(input())
t=[]
time=0
chores=0
for i in range(0, i):
      t.append(int(input()))
t.sort()
for i in range(0, len(t)):
      if t[i]+time<=h:
          time=time+t[i]
          chores=chores+1
print(chores)