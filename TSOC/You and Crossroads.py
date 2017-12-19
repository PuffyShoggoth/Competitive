h=int(input())
q=[]
n=h*2
mq=0
nq=1
tq=0
tqq=0
for i in range(0, n):
   q.append(input())
for i in range(0, h):
   tq+=q[i][h:n].count("g")
   tqq+=q[i][0:h].count("g")
if tq>mq: mq=tq
if tqq>mq: 
   mq=tqq
   nq=2
tq=0
tqq=0
for i in range(h, n):
   tqq+=q[i][h:n].count("g")
   tq+=q[i][0:h].count("g")
if tq>mq: 
   mq=tq
   nq=3
if tqq>mq: 
   mq=tqq
   nq=4
print(nq)