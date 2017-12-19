import itertools
def twentyfour(a, b, c, d):
  if b ==0:
    if a>24: return 0
    else: return a
  if a%b==0: h=twentyfour(a//b, c, d, 0)
  else: h=0
  return max(twentyfour(a-b, c, d, 0), twentyfour(a+b, c, d, 0), twentyfour(a*b, c, d, 0), h)
def patterntwo(a, b, c, d):
  if c%d==0: h=twentyfour(a, b, c//d, 0)
  else: h=0
  return max(twentyfour(a, b, c+d, 0), twentyfour(a, b, c*d, 0), twentyfour(a, b, c-d, 0), h)
n=int(input())
for i in range(0, n):
   h=[]
   for j in range(0, 4):
      h.append(int(input()))
      q=list(itertools.permutations(h, 4))
      number=0
      big=0
      for i in range(0, len(q)):
        t, w, e, r=q[i][0], q[i][1], q[i][2], q[i][3]
        number=max(twentyfour(t, w, e, r), patterntwo(t, w, e, r))
        if number==24:
           big=number
        elif number>big: big=number
   print(big)