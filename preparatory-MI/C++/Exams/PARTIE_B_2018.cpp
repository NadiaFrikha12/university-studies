#include <iostream>
using namespace std;

class personne {
private:
    int id;
    int age;

public:
    // Constructeur
    personne(int i = 0, int a = 0) : id(i), age(a) {}

    // Surcharge de l'opérateur <
    bool operator<(const personne& p) const {
        return age < p.age; // Comparaison par âge
    }

    // Accesseurs pour afficher les propriétés
    int getId() const { return id; }
    int getAge() const { return age; }
};

// Fonction pour afficher un tableau de personnes
void afficher(const personne t[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "ID: " << t[i].getId() << ", Âge: " << t[i].getAge() << " ans" << endl;
    }
}

// Fonction pour échanger deux éléments (générique)
template <class T>
void permuter(T* a, T* b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

// Fonction de tri par sélection (générique)
template <class T>
void triselection(T t[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (t[j] < t[min_idx]) {
                min_idx = j;
            }
        }
        permuter(&t[min_idx], &t[i]);
    }
}

int main() {
    // Test avec un tableau de personnes
    personne personnes[] = {personne(1, 25), personne(2, 20), personne(3, 30)};
    int n = sizeof(personnes) / sizeof(personnes[0]);

    cout << "Avant le tri : " << endl;
    afficher(personnes, n);

    triselection(personnes, n);

    cout << "Après le tri (par âge) : " << endl;
    afficher(personnes, n);

    return 0;
}
