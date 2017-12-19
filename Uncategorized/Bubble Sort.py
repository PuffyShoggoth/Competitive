numby=int(input()) #I like pie, and I'm a bit hyper now, 'cause I drank too much coffee
l=[int(i) for i in input().split()] #Although that's really not relevant

#So please ignore these comments
h=""
for jooka in range(0, len(l)):
             h=h+" "+str(l[jooka])
print(h[1:len(h)])
for ia in range(0, numby):
  for i in range(0, numby-1):
     if l[i] >l[i+1]:
         l[i], l[i+1]=l[i+1], l[i]
         h=""
         for jooka in range(0, len(l)):
             h=h+" "+str(l[jooka])
         print(h[1:len(h)])