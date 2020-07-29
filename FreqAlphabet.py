from collections import Counter

def getmaxval(i):
    charlist = Counter(i).most_common()
    temp = charlist[0]
    return temp[1]

l = int(input())

fp = list(input())
sp = list(input())
maxval = 0
temp = []

val = getmaxval(fp)
if val>maxval:
    maxval = val

val = getmaxval(sp)
if val>maxval:
    maxval = val

np = []
for i in range(0, l):
    if fp[i] != sp[i]:
        np.append(fp[i])
        np.append(sp[i])
    else:
        np.append(fp[i])
        
val = getmaxval(np)
if val>maxval:
    maxval = val

print(maxval)