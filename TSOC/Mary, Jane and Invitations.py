n=int(input())
s=input()
i=0
while i<len(s):
   if s[i]=="X":
      count=1
      ind=i+1
      while s[ind]=="X":
         count+=1
         ind+=1
      s=s[0:i-count]+s[ind]+s[i-count+1:i]+s[ind+1:len(s)]
      continue
   i+=1
for k in range(n):
   p=input()
   if s[k]=="A": print("Dear "+p+", beloved artist, I would love to have you at my party. Come to my crib on April 20th.")
   elif s[k]=="O": print("Dear "+p+", beloved occasion enthusiast, come to my crib to celebrate this very special day.")
   elif s[k]=="R": print("Dear "+p+", April 20th is happening again this year. Don't miss out.")