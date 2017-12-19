o=int(input())
h=input()
r, b, y=False, False, False
d={'B':b, 'R': r, 'Y':y}

for i in range(0, o):
    if d[h[i]]==True:
        if h[i]!=h[i-1]:
            d[h[i]]=False
            break
    elif d[h[i]]== False: d[h[i]]=True
if d['B'] and d['R'] and d['Y']: print('Organized')
else: print('FIX YOUR BEADS!')