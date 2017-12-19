def alt(h, dt):
    t=0
    while True:
       t=t+1
       a=(-6)*(t**4)+ h*(t**3)+2*(t**2)+t
       
       if a<=0:
                print('The balloon first touches ground at hour:')
                print(t)
                break
       elif t==dt:
           print('The balloon does not touch ground in the given time.')
           break
    return
alt(int(input()), int(input()))