for i in range(10):
   t=[int(x) for x in input().split()]
   sp=(t[0]*86400+t[1]*3600+t[2]*60)*1000+2242663
   d=int(sp/88642663)
   sp=sp%(88642663)
   h=int(sp/(88642663/24))
   sp=sp%(88642663/24)
   m=int(sp/(88642663/1440))
   print("Day", str(d)+",", "0"*(2-len(str(h)))+str(h)+":"+"0"*(2-len(str(m)))+str(m))