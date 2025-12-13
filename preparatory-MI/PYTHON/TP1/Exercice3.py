#FRIKHA NADIA MI2A
from math import*
m = int(input("donner m : "))
while(m<0):
    m= int(input("donner m : "))

n= m
while n>=14 :
    n= (n//10) - (2 * (n%10))

if(abs(n) == 7 or abs(n) == 0):
    print("l'entier est divisible par 7")
else : 
    print("l'entier n'est divisible par 7")

