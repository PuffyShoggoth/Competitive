M=input()
F=input()
J=int(input())
for k in range(0, J):
    B=input()
    for A in range(0, 10, 2):
         if 123>ord(B[A//2])>96:
            if (B[A//2]==M[A] or B[A//2]==M[A+1]) and (B[A//2]==F[A] or B[A//2]==F[A+1]):
               if A==8: 
                  print('Possible baby.')
                  break
               continue
            else: 
               print('Not their baby!')
               break
         elif 91>ord(B[A//2])>0:
             if (B[A//2]==M[A] or B[A//2]==M[A+1]) or (B[A//2]==F[A] or B[A//2]==F[A+1]):
               if A==8: 
                  print('Possible baby.')
                  break
               continue
             else: 
                print('Not their baby!')
                break
