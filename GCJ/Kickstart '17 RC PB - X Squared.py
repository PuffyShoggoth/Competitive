tstcs = int(input())
for dnr in range(tstcs):
   gdn = True
   while gdn:
       try:
           gdn = False
           n = int(input())
       except ValueError:
           gdn = True
   l = [0 for i in range(n)]
   fcol = -1
   pob = True
   dn = [[False for i in range(n)] for j in range(n)]
   for i in range(n):
      s = input()
      numx = s.count("X")
      if numx == 1:
         if fcol<0: 
            fcol = s.index("X")
            if l[fcol]>0: 
               pob = False
               break
         else:
            pob = False
            break
      elif numx == 2:
         tpf = s.index("X")
         tps = s[tpf+1:].index("X")+tpf+1
         if tpf == fcol or tps == fcol: 
            pob = False
            break
         else:
            dn[tpf][tps] = not dn[tpf][tps]
            l[tpf]+=1
            l[tps]+=1
      else:
         pob = False
         break
   if fcol<0: pob = False
   if pob:
      for i in range(n):
         if i!=fcol:
            if l[i]!=2 or (True in dn[i]): 
               pob = False
               break
   if pob:
      print("Case #"+str(dnr+1)+": POSSIBLE")
   else:
      print("Case #"+str(dnr+1)+": IMPOSSIBLE")