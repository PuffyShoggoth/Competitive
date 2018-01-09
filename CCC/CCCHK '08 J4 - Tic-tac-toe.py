import sys
n = int(sys.stdin.readline())

def wins(l):
   l2 = [0, 0]
   if l[0][0]=="X" and l[1][1]=="X" and l[2][2]=="X": l2[0]+=1
   elif l[0][0]=="O" and l[1][1]=="O" and l[2][2]=="O": l2[1]+=1
   if l[0][2]=="X" and l[1][1]=="X" and l[2][0]=="X": l2[0]+=1
   elif l[0][2]=="O" and l[1][1]=="O" and l[2][0]=="O": l2[1]+=1
   return l2
def hwins(l):
   l2 = [0,0]
   for i in range(3):
      if l[i]=="XXX": l2[0]+=1
      elif l[i]=="OOO": l2[1]+=1
   return l2
def vwins(l):
   l2 = [0,0]
   for i in range(3):
      if l[0][i]=="X" and l[1][i]=="X" and l[2][i]=="X": l2[0]+=1
      elif l[0][i]=="O" and l[1][i]=="O" and l[2][i]=="O": l2[1]+=1
   return l2
for i in range(n):
   l = sys.stdin.readline()
   l = [l[0:3], l[3:6], l[6:9]]
   p = wins(l)
   p2 = hwins(l)
   p3 = vwins(l)
   nx = 0
   no = 0
   for i in l:
      nx+=i.count("X")
      no+=i.count("O")
   if no!=(nx-1) and no!=nx: print("no")
   elif no==nx and sum([p[0], p2[0], p3[0]])>0: print("no")
   elif no==(nx-1) and sum([p[1], p2[1], p3[1]])>0: print("no")
   else:
      if sum(p2)>1 or sum(p3)>1: print("no")
      elif sum([p3[0], p[0], p2[0]])>0 and sum([p3[1], p[1], p2[1]])>0: print("no")
      else: print("yes")