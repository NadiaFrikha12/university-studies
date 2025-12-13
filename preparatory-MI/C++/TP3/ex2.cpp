#include<iostream>
using namespace std;

class tab{
    private :
        int taille_max;
        int nb_e ; 
        int *t;

    public :
        tab (int max){
            cout<<"constructeur avec taille maximale"<<endl;
            taille_max = max;
            nb_e = 0;
            t= new int[max];
        }

        tab (const tab &o){
            cout<<"constructeur par recopie"<<endl;
            taille_max = o.taille_max;
            nb_e = o.nb_e;
            t = new int[taille_max];
            memcpy (t, o.t, nb_e * sizeof(int));
            
        }

        void afficheProp (){
            cout<<"affichage propriete"<<endl;
            cout<<"taille max : "<<taille_max<<endl;
            cout<<"nb elements : "<<nb_e<<endl;
        }

        void affiche(){
            cout<<"affichage"<<endl;
            if (nb_e == 0){
                cout<<"le tableau est vide"<<endl;
                return; 
            }
            for (int i=0 ; i<nb_e; i++){
                cout<<"t["<<i<<"] : "<<t[i]<<endl;
            }
        }


        tab operator= (const tab &o){
            cout << "operateur d'affectation" <<endl;
            if (this != &o){ //eviter l'auto-affectation
                delete[] t; //liberer l'ancien tableau 
                nb_e= o.nb_e;
                t= new int[taille_max];
                memcpy(t ,o.t ,nb_e * sizeof(int)); 
            }
            return *this; 
        } 

        tab operator+ (const tab &o){
            cout <<"operateur +"<<endl;

            tab result(taille_max + o.taille_max);
            result.nb_e = nb_e + o.nb_e;
    
            memcpy (result.t, t , nb_e * sizeof(int));
            memcpy (result.t + nb_e, o.t, o.nb_e * sizeof(int));

            return result;
        }

        void ajouter(int valeur) {
            if (nb_e < taille_max) {
                t[nb_e++] = valeur;
            } else {
                cout << "Erreur : le tableau est plein !" << endl;
            }
        }

        ~tab() {
            cout<<"destruction"<<endl; 
            cout<<"nb element : "<<nb_e<<endl;
            delete[] t; 
        }

        friend tab operator- (const tab& , const tab& );
};

tab operator- (const tab &o1, const tab &o2){
    cout<<"operateur - "<<endl;
    tab result(o1.taille_max );
    for (int i=0; i < o1.nb_e ;i++){
        bool found = false;
        for (int j =0 ; j< o2.nb_e ; j++){
            if (o1.t[i] == o2.t[j]){
                found = true; 
                break;
            }
        }
        if (!found){
            result.t[result.nb_e++] =o1.t[i]; 
        }
    }
    return result;
}


int main(){
    // Création d'un tableau avec une taille maximale
    tab t1(5);

    // Ajout d'éléments au tableau t1
    t1.ajouter(10);
    t1.ajouter(20);
    t1.ajouter(30);

    // Affichage des propriétés et du tableau
    t1.afficheProp();
    t1.affiche();

    // Création d'un deuxième tableau
    tab t2(5);
    t2.ajouter(15);
    t2.ajouter(25);

    // Affichage de t2
    t2.afficheProp();
    t2.affiche();

    // Test de l'opérateur +
    tab t3 = t1 + t2;
    cout << "Union de t1 et t2 :" << endl;
    t3.affiche();

    // Test de l'opérateur -
    tab t4 = t1 - t2;
    cout << "Différence de t1 et t2 :" << endl;
    t4.affiche();

    return 0;
}