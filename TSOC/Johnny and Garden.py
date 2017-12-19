h=input()
if "." in h and len(h)-h.index(".")<=6: 
   r=h[h.index(".")+1:len(h)]
   r.lower()
   print("\""+h[0:h.index(".")]+"\"", "- "+r)
else: 
   f=input()
   f=f.lower()
   print("\""+h+"\"", "- "+f)