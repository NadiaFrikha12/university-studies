#include<iostream>
#include<cstring>
using namespace std;

class objetassure {
    protected :
        float montant;
        char* type;
    public : 
        objetassure (int m=0, char* s="" ): montant(m){
            cout<<"constructeur objetassure"<<endl;
            type = new char[strlen(s) + 1];
            strcpy(type, s);
        }

        virtual void affiche() {
            cout<<"montant ="<<montant<<endl;
            cout<<"tpe : "<<type<<endl;
        }

        virtual ~objetassure() {
        delete[] type;
        cout << "Destructeur objetassure" << endl;
    }
};

class ordinateur : public virtual objetassure {
    protected : 
        int ram;
        int hd; 
    public : 
        ordinateur( int m=0, char* s="", int r=0, int h=0): objetassure(m,s), ram(r), hd(h){
            cout<<"constructeur ordinateur"<<endl;
        }

        virtual void affiche(){
            objetassure::affiche();
            cout<<"ram = "<<ram<<endl;
            cout<<"hd = "<<hd<<endl;
        }
};

class bagage : public virtual objetassure {
    protected :
        char* typeb;
        float poids; 
    public : 
        bagage (int m=0, char* s="", char* b="", float p=0) : objetassure(m,s), poids(p){
             typeb = new char[strlen(b) + 1];
            strcpy(typeb, b);
            cout<<"constructeur bagage"<<endl;
        }

        virtual ~bagage() {
        delete[] typeb;
        cout << "Destructeur bagage" << endl;
    }


        virtual void affiche(){
            objetassure::affiche();
            cout<<"type = "<<type<<endl;
            cout<<"poids = "<<poids<<endl;
        }
};

class ordinateurportable : public ordinateur, public bagage {
    private : 
        float epaisseur;
    public : 
        ordinateurportable (int m=0, char* s="", int r=0, int h=0, char* b="", float p=0, float e=0) : objetassure(m,s),ordinateur(m,s,r,h), bagage(m,s,b,p),epaisseur(e) {
            cout << "Constructeur ordinateurportable" << endl;
        }
        void affiche(){
            
            ordinateur::affiche();
    
            cout << "Epaisseur = " << epaisseur << " cm" << endl;
        }

};


int main() {
    ordinateurportable op(10, "Ordinateur Portable", 16, 512, "Bagage", 2.5, 1.8);
    op.affiche();

    return 0;
}
