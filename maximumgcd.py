def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b) 

num = int(input())

for i in range(0, num):
    max = 0
    numList = [int(n) for n in input().split()]
    for j in range(0, len(numList)):
        for k in range(j+1, len(numList)):
            temp = gcd(numList[j], numList[k])
            if max<temp:
                max = temp
    
    print(max)
