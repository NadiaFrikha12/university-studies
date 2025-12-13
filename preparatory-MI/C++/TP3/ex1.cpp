#include<iostream>
using namespace std;

class matrice; 

class vect{
    private : 
        int *t;
        int n; 
    public: 
        vect (int n){
            cout<<"construction vect"<<endl;
            t= new int[this->n =n];
        }

        vect(){
            cout<<"constructeur sans parametre"<<endl;
            n=0;
            t=NULL;
        }

        vect (const vect &v){
            cout<< "constructeur par recopie"<<endl;
            t=new int [this->n=v.n];
            memcpy(t, v.t, n*sizeof(int));
        }

        void definir ( int n){
            if (t != NULL){
                delete[] t; // Libère l'ancien tableau
            }
            cout<<"definir vecteur "<<endl;
            t= new int[this->n =n];
        }

        void remplir (){
            cout<<"remplir vecteur"<<endl;
            for (int i=0; i<n ; i++){
                cin >> t[i];
            }
        }

        int intersection (vect v1, vect v2){
            cout<<"debut intersection"<<endl;

            // Déterminer la taille maximale possible pour l'intersection
            int max = (v1.n < v2.n)? v1.n : v2.n ;
            int *tab = new int[max];
            int k=0;

            //trouver les elemnts en communs
            for (int i=0; i< v1.n ; i++){
                for (int j = 0; j< v2.n ; j++){
                    if (v1.t[i] == v2.t[j]){
                        tab[k] = v1.t[i];
                        k++;
                        break; //eviter de repeter le même element 
                    }
                }
            }

            // Mettre à jour l'objet courant avec les éléments communs
            this->definir(k);
            for(int i=0; i<k; i++){
                t[i] = tab[i];
            }
            delete[] tab;
            cout<<"fin intersect"<<endl;
            return (k); 
        }

        void afficher (){
            cout<<"affichage"<<endl;
            for(int i=0; i<n; i++){
                cout<<t[i]<<endl;
            }
        }

        ~vect (){
            cout<<"destruction"<<endl;
            this->afficher();
            delete[] t; 
        }

        friend vect prod(vect, matrice);
};

class matrice {
    private: 
        int m[3][3];
    public:
        matrice ( int t[3][3] ){
            cout<<"cosnt matrice"<<endl;
            for (int i=0; i<3 ; i++){
                for (int j=0; j<3; j++){
                    m[i][j]= t[i][j];
                }
            }
        }

        ~matrice(){
            cout<<"destruction matrice"<<endl;
        }  

        friend vect prod (vect, matrice);
};


vect prod (vect v, matrice m1){
    vect res(3);
    int i,j;
    for ( i=0;i <3; i++){
        double s=0;
        for ( j=0 ; j<3; j++ ){
            s += m1.m[i][j] * v.t[j];
        }
        res.t[i]= s; 
    }
    return res; 
}

int main() {
    int t[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<"t["<<i<<"]["<<j<<"] = ";
            cin>>t[i][j];
        }
    }
        
    matrice m(t);
    vect v(3);
    vect res; 
    res=prod(v,m);

}