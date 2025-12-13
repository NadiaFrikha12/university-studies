#FRIKHA NADIA MI2A
from math import* 

a= str(input("donner l'entier a convertir : "))
b= int(input("donnez la base de a : "))
while (not( 2<= b<=8)):
    b= int(input("donnez la base de a : "))

#convertir a dans la base 10 
r=0
n=len(a)-1
for i in range (len(a)):
    r = r + int(a[i])*pow(b,n)
    n=n-1

print (a, "dans la base 10 est : ", int(r))