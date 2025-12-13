list = [1, 8, 2, 13, 5, 4]
n = int(input("saisir le nombre d'element"))
for i in range (n) :
    s = int (input ("saisir l'entier"))
    list.append(s)
m = 0 
for i in range (n): 
    m+= list[i]
    m = m/n 

var = 0
for i in range (n) : 
    var += abs(list[i] - m)
var = var / n 
print (var) 