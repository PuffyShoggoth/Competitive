def fromtup(x):
   q=''
   for i in range(0, len(x)):
      if type(x[i])==tuple: q=q+fromtup(list(x[i]))
      else: q=q+x[i]+' '
   return q



while True:
    h=input().split()
    if h[0]=='0': break
    if len(h)<3: 
            if h[0].isdigit()==False:
               print(h[1], h[0])
            else: print(h[0])
            continue
    p=[h[len(h)-2], h[len(h)-1]]
    for i in range(len(h)-3, -1, -1):
        if h[i].isdigit()==True:
            p.insert(0, h[i])
        else: 
            p[0]=tuple([p[0], p[1], h[i]])
            del p[1]
    print(fromtup(p))