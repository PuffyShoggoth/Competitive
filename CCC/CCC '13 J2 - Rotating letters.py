word=str(input())
usableLetters=['I','O','S','H','Z','X','N']
Bokrug=0
for letters in range(0, len(word)):
  for letterGood in range(0, 7):
   if word[letters]==usableLetters[letterGood]:
      Bokrug=Bokrug+1
if Bokrug!=len(word):
   print('NO')
else: print('YES')