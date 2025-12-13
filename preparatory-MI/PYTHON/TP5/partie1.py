import numpy as np 
import matplotlib.pyplot as plt

#1.Donner l’instruction python qui crée trois tableaux contenant respectivement 10 zéro, 10 un et 10 cinq.

T1 = np.zeros(10,int)
print (T1)
T2 = np.ones(10,int)
print (T2)
T3 = np.full(10,5,int)
print (T3)

#2.Donner l’instruction qui crée un tableau contenant les entiers de 30 à 70.
T4 = np.arange(30, 71)
print (T4)

#3.Donner l’instruction qui crée un tableau contenant les entiers pairs de 30 à 70.
T4 = np.arange(30, 71,2)
print (T4)

#4.Donner l’instruction qui permet de créer une matrice d’identité 3x3.
T5 =np.identity(3)
print(T5)

#5.Donner l’instruction qui permet de créer une matrice 3x4 avec des valeurs variant de 10 à 21.
T6 =np.arange(10, 22).reshape(3, 4)
print(T6)

#6.Donner les instructions qui permettent de créer une matrice 10x10, dans laquelle les éléments aux bord sont égaux à 1, tandis que ceux à l’intérieur sont égaux à 0.
T7=np.ones((10,10))
T7[1:9,1:9]=0
print(T7)

#7.Donner l’instruction qui crée une matrice 5x5 dont les éléments de la diagonale principales sont respectivement 1, 2, 3, 4 et 5.
T8=np.diag((1,2,3,4,5))
print(T8)

#8.Donner les instructions qui permettent de créer une matrice et d’afficher la somme de tous les éléments, la somme par colonne ainsi que la somme par ligne.
print(np.sum(T8))
print(np.sum(T8, axis=0))
print(np.sum(T8, axis=1))

#9.Donner les instructions qui permettent de créer une matrice carrée et d’afficher la somme des éléments de la diagonale principale ainsi que la somme des éléments de la diagonale secondaire.
T9= np.array ([[1,2,3],[4,5,6],[7,8,9]])
print(T9)
print( np.trace(T9))
print(np.trace(np.fliplr(T9)))

#10.Donner les instructions qui permettent de tracer la courbe de la fonction sinus sur l’intervalle [-3pi,3pi].
x = np.linspace(-3 * np.pi, 3 * np.pi, 100)
y = np.sin(x)
plt.plot(x,y)
plt.show()

#11.Soit le tableau T1 à une dimension contenant les valeurs de 6 à 11. Donner les instructions qui
#permettent de créer respectivement une matrice M1 de taille 2x3, une matrice M2 de taille 3x2
#et une M3 de taille 6x1 à partir de T1.

T10=np.arange(6,12)
print(T10)
M1=T10.reshape(2,3)
print(M1)
M2=T10.reshape(3,2)
print(M2)
M3=T10.reshape(6,1)
print(M3)

#12.Étant donné un tableau T à une dimension initialisé par 3 valeurs quelconques. Donner l’instruction qui permet d’augmenter la taille du tableau à 4 fois sa taille d’origine.
T11 = np.array([1, 2, 3])
T = np.resize(T11, 4 * T11.size)  #T22=np.array([T]*4)
print(T)

#13. Soit une matrice M de taille 5x3 initialisée par des 0. Donner l’instruction qui permet d’ajouter une ligne et deux colonnes à M.
M = np.zeros((5, 3))
M = np.vstack([M, np.zeros((1, 3))])
M = np.hstack([M, np.zeros((6, 2))])
print(M)

#14. Écrire une fonction python qui permet de retourner la transposée d’une matrice M (sans utiliser la fonction transpose de numpy).
m1=np.array([[1,2,3],[4,5,6],[7,8,9]])
def transpose(m):
    t=m.shape
    m2=np.zeros((t[1],t[0]),int)
    for i in range (len(m)):
        m2[i][j]=m1[j][i]