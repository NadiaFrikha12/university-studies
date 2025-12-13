list = []
list_pair = []
list_impair = []

l = int(input("donner la longueur"))
for i in range (list) : 
    if i % 2 == 0 : 
        list_pair.append(i)
    else : 
        list_pair.append(i)

list_pair.sort()
list_impair.sort()

list = list_pair + list_impair
print (list)
