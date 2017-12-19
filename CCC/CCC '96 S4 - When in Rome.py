nu={'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D': 500, 'M':1000}
ni=['M', 'D', 'C', 'L', 'X', 'V', 'I']
def romadd(nums):
   stock=0
   plus=0
   prev=''
   count=0
   for g in range(0, len(nums)):
            if nums[g]=='+': stock, plus = plus, 0
            elif nums[g]=='=': return stock+plus
            if prev=='I' and (nums[g]=='V' or nums[g]=='X'): plus=plus-nu['I']*2
            elif prev=='X' and (nums[g]=='L' or nums[g]=='C'): plus=plus-nu['X']*2
            elif prev=='C' and (nums[g]=='D' or nums[g]=='M'): plus=plus-nu['C']*2
            if nums[g]!='+': plus=plus+nu[nums[g]]
            prev=nums[g]
def numtoro(x):
   toro=''
   for i in ni:
      if x//nu[i]>3:
           if len(toro)>=1:
            if toro[len(toro)-1]==ni[ni.index(i)-1]: toro=toro[0:len(toro)-1]+i+ni[ni.index(i)-2]
           else: toro=toro+i+ni[ni.index(i)-1]
      else: toro=toro+x//nu[i]*i
      x=x%nu[i]
   return toro
h=int(input())
for i in range(0, h):
      numb=input()
      yuu=romadd(numb)
      if yuu>1000: print(numb+'CONCORDIA CUM VERITATE')
      else: print(numb+numtoro(yuu))