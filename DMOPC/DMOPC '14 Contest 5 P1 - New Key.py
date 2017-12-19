N=['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
Aj=['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J']
Kt=['K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T']
Uz=['U', 'V', 'W', 'X', 'Y', 'Z']
w=input()
q=''
for i in range(0, len(w)):
    if w[i] in N:
        if N.index(w[i])==0: q=q+N[9]
        else: q=q+Aj[N.index(w[i])-1]
    elif w[i] in Aj:
        if Aj.index(w[i])==0: q=q+Aj[9]
        else: q=q+Kt[Aj.index(w[i])-1]
    elif w[i] in Kt:
        if Kt.index(w[i])==0: q=q+Kt[9]
        else: q=q+Uz[Kt.index(w[i])-1]
print(q)
