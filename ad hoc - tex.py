import sys
i = 0
text = sys.stdin.readlines()
for line in text:
    res = ""
    for char in line:
        if char != "\"":
            res=res+char
        else:
            if i==0:
                res=res+(str("``"))
                i=1
            elif i==1:
                res=res+(str("\'\'"))
                i=0
    print(res, end='')
