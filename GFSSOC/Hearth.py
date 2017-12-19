D_WsNumberCards, D_WsNumberCrystals = [int(i) for i in input().split()]
D_WsDict = dict() 
D_WsCardNames = list()
for _ in range(D_WsNumberCards):
   D_WsCardName, D_WsCardCost = [i for i in input().split()]
   D_WsDict[D_WsCardName] = int(D_WsCardCost)
   D_WsCardNames.append(D_WsCardName)
D_WsCardNames.sort()
for i in range(D_WsNumberCards-2):
   for j in range(i+1, D_WsNumberCards-1):
      for k in D_WsCardNames[j+1:]:
         if (D_WsDict[D_WsCardNames[i]]+D_WsDict[D_WsCardNames[j]]+D_WsDict[k])<=D_WsNumberCrystals:
            print(D_WsCardNames[i], D_WsCardNames[j], k)