#FRIKHA NADIA MI2A

a=int(input("donner a:"))
b=int(input("donner b:"))
c=int(input("donner c:"))

while c!=-1:
    moyenne=(a+b+c)/3
    print("la moyenne mobile est : ", moyenne)
    a=b
    b=c
    c=int(input("donner c:"))