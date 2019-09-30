def reverse(s):
    return s[::-1]

times = int(input())

for i in range (0, times):

    num = str(input())
    count = 0

    while True:
        
        num = str(num)
        revved = reverse(str(num))

        if num == revved:

            print(str(count)+" "+str(num))
            break

        else:

            num = int(num)
            revved = int(revved)
            num = num+revved
            count+=1

    
