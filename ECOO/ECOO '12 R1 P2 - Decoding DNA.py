d = {'A':'U', 'T':'A', 'C':'G', 'G':'C'}
dn = {'A':'T', 'T':'A', 'C':'G', 'G':'C'}
def trnsd(cs):
    tp = ""
    for i in range(len(cs)-1, -1, -1):
        tp=tp+dn[cs[i]]
    return tp
for dnr in range(5):
    s = input().strip()
    fv = ""
    st = s.index("TATAAT")+10
    for i in range(st, len(s)-6):
        if(trnsd(s[i:i+6]) in s[i+6:]):
           for j in range(st, i):
               fv = fv+d[s[j]]
           #print(st, i, s[i:i+6], trnsd(s[i:i+6]))
           break
    print(str(dnr+1)+": "+fv)