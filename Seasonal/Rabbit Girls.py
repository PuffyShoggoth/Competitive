girls=int(input())
groups=int(input())
h=girls%groups
if h==0: print(0)
elif girls<groups: print(groups-girls)
else: print(min(groups-h, h))