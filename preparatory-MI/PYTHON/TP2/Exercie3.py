L= [32, 5, 12, 8, 3, 75, 2, 15]
min= L[0]
max=L[0]
for i in range (len(L)-1): 
    if L[i]> max : 
        max = L[i]
    else: 
        if L[i]< min :
            min = L[i]

print("max: ", max)
print("mix: ", min)
