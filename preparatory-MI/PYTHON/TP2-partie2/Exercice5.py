n = int (input("donner un entier >= n"))
list = [ i for i in range ( 2, n+1)]
for i in range (i+1 , len(list)) : 
    if (list[j] % list[i] == 0) : 
        list[j] = 0
list1 = [i for i in list if i!= 0]
list = list1
print (list)

