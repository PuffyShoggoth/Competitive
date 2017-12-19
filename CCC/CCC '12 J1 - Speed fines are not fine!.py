x=int(input())
y=int(input())
if x>=y:
    print('Congratulations, you are within the speed limit!')
else:
    overspeedlimitby=y-x
    if overspeedlimitby<=20:
        print('You are speeding and your fine is $100.')
    elif overspeedlimitby<=30:
        print('You are speeding and your fine is $270.')
    else:
        print('You are speeding and your fine is $500.')