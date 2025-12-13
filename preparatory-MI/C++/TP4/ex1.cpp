#include<iostream>
#include<string>
using namespace std;

class Article {
    protected :
        string nom;
        double prix;
    public : 
        Article(string n = "", double p = 0.0) : nom(n), prix(p) {}

        double GetPrix(){
            cout<<"getprix :";
            return prix;
        }

        void ChangerPrix(double p){
            cout<<"changer prix"<<endl;
            prix = p; 
        }

        void afficher(){
            cout<<"prix: "<<prix<<endl;
        }
};


class ArticleSolde : public Article {
    private: 
        int remise ;
    public: 
        // Constructeur
        ArticleSolde(string n = "", double p = 0.0, int r = 0) : Article(n, p), remise(r) {}

        void ChangerRemise (int r){
            cout<<"changer remise";
            remise =r;
        }

        double GetPrix (){
            cout<<"prix solde : ";
            double m = prix - (prix * remise / 100 ) ;
            return m; 
        }

        void afficher(){
            cout<<"prix article d'origine: "<<prix<<endl;
            cout<<"pourcentage remise : "<<remise<<"%"<<endl;
            cout<<"prix article solde :"<<GetPrix ()<<endl;
        }

};

int main() {
    // Test des classes
    Article a("Chaise", 50.0);
    a.afficher();
    cout << endl;

    ArticleSolde as("Table", 100.0, 20);
    as.afficher();
    cout << endl;

    as.ChangerRemise(30);
    as.afficher();

    return 0;
}