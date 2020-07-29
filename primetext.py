from sys import stdin

mydict = {}
alph = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
idx = 1
for c in alph:
    mydict[c] = idx
    idx+=1

def isPrime(i):
    i = int(i)
    if i >= 1:
        if i==4: 
            return False
        for x in range(2, i//2):
            if i%x == 0:
                return False
            else:
                continue

        return True

    else:
        return False 

for line in stdin:
    val = 0
    for c in line:
        if c!='\n':
            val+=mydict[c]
    
    if isPrime(val)==True:
        print("It is a prime word.")
    else:
        print("It is not a prime word.")