numboxes=int(input())
boxes=[]
for i in range(0, numboxes):
   h, w, l=map(int, input().split())
   boxes.append([h, w, l])
   
numitems=int(input())
for q in range(0, numitems):
   smallerboxes=[]
   tya=False
   h, w, l=map(int, input().split())
   sides=[h, w, l]
   for i in range(0, len(sides)):
      for j in range(0, len(sides)):
         if i==j: continue
         for k in range(0, len(sides)):
            if i==k or j==k: continue
            for g in range(0, len(boxes)):
             if sides[i]<=boxes[g][0] and sides[j]<=boxes[g][1] and sides[k]<=boxes[g][2]:
                  smallerboxes.append(boxes[g][0]*boxes[g][1]*boxes[g][2])
                  tya=True
   if tya==True: print(min(smallerboxes))
   if tya==False: print('Item does not fit.') 