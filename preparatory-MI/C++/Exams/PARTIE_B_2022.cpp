#include <iostream>
#include <cstring>
using namespace std;

class composant {
private:
    int id;
    char* libelle;
    float pa;

public:
    // Constructeur sans paramètres avec initialisation
    composant(int i = 0, const char* l = "", float p = 0.0) : id(i), pa(p) {
        libelle = new char[strlen(l) + 1]; // Allocation correcte
        strcpy(libelle, l);
    }

    // Constructeur par recopie
    composant(const composant& p) : id(p.id), pa(p.pa) {
        libelle = new char[strlen(p.libelle) + 1];
        strcpy(libelle, p.libelle);
    }

    // Destructeur
    ~composant() {
        delete[] libelle;
    }

    // Méthode cout
    float cout() const {
        return pa;
    }

    // Surcharge de l'opérateur (char*)
    operator const char*() const {
        return libelle;
    }

    // Méthode view
    void view() const {
        cout << "ID: " << id << ", Libelle: " << libelle << ", Prix: " << pa << " dinars" << endl;
    }

    // Surcharge de l'opérateur < pour le tri
    bool operator<(const composant& other) const {
        return pa < other.pa;
    }

    // Surcharge de l'opérateur >= (utile pour max/min)
    bool operator>=(const composant& other) const {
        return pa >= other.pa;
    }
};

// Template de tableau
template <class T>
class tableau {
private:
    T* v;
    int n;         // Taille actuelle
    int dim;       // Capacité maximale

public:
    // Constructeur avec dimension
    tableau(int taille = 10) : n(0), dim(taille) {
        v = new T[dim];
    }

    // Destructeur
    ~tableau() {
        delete[] v;
    }

    // Méthode pour insérer un élément
    void insere(const T& e) {
        if (n < dim) {
            v[n++] = e;
        } else {
            cout << "Le tableau est plein" << endl;
        }
    }

    // Méthode pour obtenir l'indice du max
    int max() const {
        int maxIndex = 0;
        for (int i = 1; i < n; i++) {
            if (v[i] >= v[maxIndex]) {
                maxIndex = i;
            }
        }
        return maxIndex;
    }

    // Méthode pour obtenir l'indice du min
    int min() const {
        int minIndex = 0;
        for (int i = 1; i < n; i++) {
            if (v[i] < v[minIndex]) {
                minIndex = i;
            }
        }
        return minIndex;
    }

    // Tri par sélection
    void triselection() {
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (v[j] < v[minIndex]) {
                    minIndex = j;
                }
            }
            permuter(&v[i], &v[minIndex]);
        }
    }

    // Permuter deux éléments
    void permuter(T* a, T* b) {
        T temp = *a;
        *a = *b;
        *b = temp;
    }

    // Affichage des éléments
    void view() const {
        for (int i = 0; i < n; i++) {
            v[i].view();
        }
    }
};

// Programme principal
int main() {
    // Création de composants
    composant c1(1, "Chaise", 20.0);
    composant c2(2, "Table", 50.5);
    composant c3(3, "Coussin", 5.25);

    // Création d'un tableau de composants
    tableau<composant> t(10);

    // Insertion des composants
    t.insere(c1);
    t.insere(c2);
    t.insere(c3);

    // Affichage avant tri
    cout << "Avant le tri :" << endl;
    t.view();

    // Tri
    t.triselection();

    // Affichage après tri
    cout << "\nAprès le tri :" << endl;
    t.view();

    // Affichage du min et du max
    int minIndex = t.min();
    int maxIndex = t.max();
    cout << "\nÉlément minimum :" << endl;
    t.view(minIndex);

    cout << "Élément maximum :" << endl;
    t.view(maxIndex);

    return 0;
}
