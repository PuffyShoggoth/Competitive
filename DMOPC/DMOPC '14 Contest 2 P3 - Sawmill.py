import sys
n=int(input())
s=[int(x) for x in sys.stdin.readline().split()]
l=[int(x) for x in sys.stdin.readline().split()]
t=0
s.sort()
l.sort()
for i in range(n):
      t+=s[i]*l[n-i-1]
print(t)