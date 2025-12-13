#FRIKHA NADIA MI2A
n=int(input("donner n : "))
while (not(n>=1)):
    n=int(input("donner n : "))

pi = 0.0
while n != 0 : 
    pi += 1/((2*n-1)*(2*n+1))
    n =2

pi *= 8

print ("l'approximation de pi est : ", pi)