def printDuplicate(str):
    n=len(str)
    count={}
    for i in range(0,n):
        if str[i] in count:
            count[str[i]]=count[str[i]]+1
        else:
            count[str[i]]=1
    for s,c in count.items():
        if c>1:
            print(s,c)
str="Prakhar"
printDuplicate(str)
