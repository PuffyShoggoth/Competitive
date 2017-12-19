w=False
def newt(x, y, xi, yi):

   newtunnel=[]
   if x!=xi:
      if xi<x: 
         for i in range(x, xi, -1):
            newtunnel.append(tuple([i, y]))
      else: 
         for i in range(x, xi):
            newtunnel.append(tuple([i, y]))
   elif y!=yi:
      if yi<y: 
         for i in range(y, yi, -1):
            newtunnel.append(tuple([x, i]))
      else: 
         for i in range(y, yi):
            newtunnel.append(tuple([x, i]))

   return newtunnel
tunnel=[]
oldtunnel=[(0, -1), (0, -3), (3, -3),(3, -5), (5, -5), (5, -3), (7, -3), (7, -7), (-1, -7), (-1, -5)]  
for i in range(0, len(oldtunnel)-1):
   a, b=oldtunnel[i]
   ai, bi=oldtunnel[i+1]
   tunnel.extend(newt(a, b, ai, bi))
x, y=-1, -5
xi, yi=x, y

while True:
   d, n=input().split()
   if d=='u':   yi=yi+int(n)
   elif d=='d': yi=yi-int(n)
   elif d=='r': xi=xi+int(n)
   elif d=='l': xi=xi-int(n)
   elif d=='q': break
   h=newt(x, y, xi, yi)
   x, y=xi, yi
   for i in range(0, len(h)):
      if h[i] in tunnel or (x, y) in tunnel:
         print(x, y, 'DANGER')
         w=True
         break
   tunnel.extend(h)
   
   
   if w==False:
      print(x, y, 'safe')
   else: 
      break