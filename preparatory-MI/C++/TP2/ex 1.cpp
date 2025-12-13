#include<iostream>
using namespace std;

class vecteur {
    private :
        int n; //longueur du tableau
        int *t; //tableau dynamique

    public :

    
        /* Des fonctions membres surdfinies
        vecteur (){
            cout<<"constructeur 0"<<endl;
            n=0;
            t=NULL;
        }

        vecteur (int n){
            cout<<"constructeur"<<endl;
            t = new int[this->n =n];
        }
        */

       //fonction membre
       vecteur (int n=0){  //int n = 0 indique que le parametre taille a une valeur par defaut 0 
            if (n != 0){
                cout<<"constructeur"<<endl;
                t = new int[this->n = n];
            }
            else{
                cout<<"constructeur 0"<<endl;
                n =0;
                t= NULL;
            }
        }
        

        void init_vecteur (int n){
            cout<<"initialisation"<<endl;
            if (t != NULL){
                delete[] t;
            }
            t = new int[this->n =n];
            for (int i=0 ; i<n ; i++){
                cin>>t[i];
            }
        }

        void view(){
            cout<<"affichage"<<endl;
            for (int i=0; i<n ; i++ ){
                cout<< t[i] << endl;
            }
        }

        int produit ( vecteur v){
            int p=0;
            if (this->n != v.n ){
                cout<<"les vecteurs ne sont pas de meme taille"<<endl;
                return 0; 
            }
            for (int i=0; i<n ; i++){
                p += t[i] * v.t[i] ;
            }
            return p;
        }

        /*Introduire une fonction membre nommée coïncide permettant de savoir si deux vecteurs ont les mêmes valeurs:
        a) En utilisant une transmission par valeur*/

        int coincide(vecteur v) {
            if (this->n != v.n) {
                cout << "Les vecteurs ne coincident pas (taille différente)" << endl;
                return 0;  // Vecteurs de tailles différentes
            }
            for (int i = 0; i < n; i++) {
                if (t[i] != v.t[i]) {
                    cout << "Les vecteurs ne coincident pas (valeurs différentes)" << endl;
                    return 0;  // Valeurs différentes
                }
            }
            cout << "Les vecteurs coincident" << endl;
            return 1;  // Vecteurs identiques
        }

        ~vecteur() {
        cout<<"destruction"<<endl;
        delete[] t;
        }

};

int main(){
    vecteur v1(3), v2(3), v3;
    
    v1.init_vecteur(3);
    v2.init_vecteur(3);
    v3.init_vecteur(3);


    v1.view();
    v2.view();
    v3.view();

    cout<<"prod ="<<v1.produit(v2)<<endl;;

    v1.coincide(v2);

    return 0;
}


/*
Pourquoi réallouer la mémoire dans init_vecteur ?
Lorsqu'un objet vecteur est initialisé avec une certaine taille via le constructeur, la mémoire dynamique pour t est allouée pour cette taille. Cependant, lorsque vous appelez init_vecteur ultérieurement, il se peut que vous souhaitiez :

Changer la taille du vecteur.
Réinitialiser le contenu avec de nouvelles valeurs.
Dans ces cas, si la taille demandée dans init_vecteur est différente de celle déjà allouée, vous devez libérer la mémoire existante (avec delete[] t) avant de réallouer pour la nouvelle taille.
*/