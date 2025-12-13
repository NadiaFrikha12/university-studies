def supprimer_occurence (liste, n) : 
    length = len(liste)
    for i in range (length - 1 , -1 , -1): 
        if liste[i] == n : 
            liste.pop(i)
    return liste 

def lire_liste() : 
    liste = []
    length = 0
    while length < 0 :
        length = int(input("donner la longueur de la liste "))
    for i in range (length):
        liste[i]= int(input(f"liste[{i}]")) 
    return liste 

liste = lire_liste()
n = int (input ("donner le nombre a supprimer"))
print(f"la liste aprés la suppression est { supprimer_occurence (liste , n)}")
