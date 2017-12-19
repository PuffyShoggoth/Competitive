string=input()
k=int(input())
q=string
for i in range(0, len(string)-k):
    if string[i:i+k]<q:
        q=string[i:i+k]
print(q)