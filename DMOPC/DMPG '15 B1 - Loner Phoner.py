h=int(input())
for i in range(0, h):
    q=input()
    if len(q)==10 and (q.startswith('416') or q.startswith('647')):
            print('('+q[0:3]+')-'+q[3:6]+'-'+q[6:10])
    else: print('not a phone number')