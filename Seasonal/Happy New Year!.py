h, m, s = map(int, input().split())
sd = 12*60*60
st = (sd-60*60*h-60*m-s)%sd
sf = st%60
st = st//60
mf = st%60
st = st//60
hf = st
print("{:02d}".format(hf)+":"+"{:02d}".format(mf)+":"+"{:02d}".format(sf))