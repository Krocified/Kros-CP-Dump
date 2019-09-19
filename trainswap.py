def bubbleCount(numlist):
    count = 0
    for i in range(len(numList)-1,0,-1):
        for j in range(i):
            if numList[j]>numList[j+1]:
                temp = numList[j]
                numList[j] = numList[j+1]
                numList[j+1] = temp
                count+=1
    return count


times = int(input())

for i in range(0, times):
    
    length = input()
    numList = [int(n) for n in input().split()]

    swaps = bubbleCount(numList)

    print("Optimal train swapping takes",int(swaps),"swaps.")