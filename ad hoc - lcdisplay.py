s = -1
n = -1

while True:
    
    s=-1
    n = []

    s, n = input().split()
    s = int(s)

    if s == 0:
        if int(n)==0:
            exit()
        else:
            continue

    topline = ""
    upper = ""
    midline = ""
    lower = ""
    botline = ""

    n = [int(i) for i in str(n)]
    
    for x in range(0,len(n)):
        if n[x]==1 :
            for i in range(0,s+2):
                topline+=(" ")

            for i in range(0,s+1):
                upper+=(" ")
            upper+=("|")

            for i in range(0,s+2):
                midline+=(" ")

            for i in range(0,s+1):
                lower+=(" ")
            lower+=("|")

            for i in range(0,s+2):
                botline+=(" ")

        elif n[x]==2 :
            topline+=(" ")
            for i in range(0,s):
                topline+=("-")
            topline+=(" ")

            for i in range(0,s+1):
                upper+=(" ")
            upper+=("|")

            midline+=(" ")
            for i in range(0,s):
                midline+=("-")
            midline+=(" ")
            
            lower+=("|")
            for i in range(0,s+1):
                lower+=(" ")

            botline+=(" ")
            for i in range(0,s):
                botline+=("-")
            botline+=(" ")

        elif n[x]==3 :
            topline+=(" ")
            for i in range(0,s):
                topline+=("-")
            topline+=(" ")

            for i in range(0,s+1):
                upper+=(" ")
            upper+=("|")

            midline+=(" ")
            for i in range(0,s):
                midline+=("-")
            midline+=(" ")
            
            for i in range(0,s+1):
                lower+=(" ")
            lower+=("|")

            botline+=(" ")
            for i in range(0,s):
                botline+=("-")
            botline+=(" ")

        elif n[x]==4 :
            for i in range(0,s+2):
                topline+=(" ")

            upper+=("|")
            for i in range(0,s):
                upper+=(" ")
            upper+=("|")

            midline+=(" ")
            for i in range(0,s):
                midline+=("-")
            midline+=(" ")
            
            for i in range(0,s+1):
                lower+=(" ")
            lower+=("|")

            for i in range(0,s+2):
                botline+=(" ")

        elif n[x]==5 :
            topline+=(" ")
            for i in range(0,s):
                topline+=("-")
            topline+=(" ")
            
            upper+=("|")
            for i in range(0,s+1):
                upper+=(" ")

            midline+=(" ")
            for i in range(0,s):
                midline+=("-")
            midline+=(" ")
            
            for i in range(0,s+1):
                lower+=(" ")
            lower+=("|")

            botline+=(" ")
            for i in range(0,s):
                botline+=("-")
            botline+=(" ")

        elif n[x]==6 :
            topline+=(" ")
            for i in range(0,s):
                topline+=("-")
            topline+=(" ")
            
            upper+=("|")
            for i in range(0,s+1):
                upper+=(" ")

            midline+=(" ")
            for i in range(0,s):
                midline+=("-")
            midline+=(" ")
            
            lower+=("|")
            for i in range(0,s):
                lower+=(" ")
            lower+=("|")

            botline+=(" ")
            for i in range(0,s):
                botline+=("-")
            botline+=(" ")

        elif n[x]==7 :
            topline+=(" ")
            for i in range(0,s):
                topline+=("-")
            topline+=(" ")

            for i in range(0,s+1):
                upper+=(" ")
            upper+=("|")

            for i in range(0,s+2):
                midline+=(" ")

            for i in range(0,s+1):
                lower+=(" ")
            lower+=("|")

            for i in range(0,s+2):
                botline+=(" ")

        elif n[x]==8 :
            topline+=(" ")
            for i in range(0,s):
                topline+=("-")
            topline+=(" ")
            
            upper+=("|")
            for i in range(0,s):
                upper+=(" ")
            upper+=("|")

            midline+=(" ")
            for i in range(0,s):
                midline+=("-")
            midline+=(" ")
            
            lower+=("|")
            for i in range(0,s):
                lower+=(" ")
            lower+=("|")

            botline+=(" ")
            for i in range(0,s):
                botline+=("-")
            botline+=(" ")

        elif n[x]==9 :
            topline+=(" ")
            for i in range(0,s):
                topline+=("-")
            topline+=(" ")
            
            upper+=("|")
            for i in range(0,s):
                upper+=(" ")
            upper+=("|")

            midline+=(" ")
            for i in range(0,s):
                midline+=("-")
            midline+=(" ")
            
            for i in range(0,s+1):
                lower+=(" ")
            lower+=("|")

            botline+=(" ")
            for i in range(0,s):
                botline+=("-")
            botline+=(" ")

        elif n[x]==0 :
            topline+=(" ")
            for i in range(0,s):
                topline+=("-")
            topline+=(" ")
            
            upper+=("|")
            for i in range(0,s):
                upper+=(" ")
            upper+=("|")

            for i in range(0,s+2):
                midline+=(" ")
            
            lower+=("|")
            for i in range(0,s):
                lower+=(" ")
            lower+=("|")

            botline+=(" ")
            for i in range(0,s):
                botline+=("-")
            botline+=(" ")

        if x<(len(n)-1) :
            topline+=(" ")
            upper+=(" ")
            midline+=(" ")
            lower+=(" ")
            botline+=(" ")

    print(topline)
    for i in range(0,s):
        print(upper)
    print(midline)
    for i in range(0,s):
        print(lower)
    print(botline)
    print("")


    

