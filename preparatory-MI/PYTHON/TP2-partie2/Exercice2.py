list = [1, 8, 2, 13, 5, 4]
list.sort() 
n= int(input("donner un entier a inserer"))
index = 0
for item in list : 
    if n> item : 
        index += 1 
    else : 
        break
list.insert(index,n)