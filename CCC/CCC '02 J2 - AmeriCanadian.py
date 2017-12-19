while True:
    V=['a','e','i','o','u','y']
    A=input()
    if A=='quit!': break
    else:
        if (A[len(A)-2:len(A)]=='or') and (A[len(A)-3] not in V):
            print(A[0:len(A)-2]+'our')
        else: print(A)

