num = int(input())

for i in range(0, num):
    x, y, n = input().split()
    x = int(x)
    y = int(y)
    n = int(n)
    print(pow(x,y,n))
        
zero = input()