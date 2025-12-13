#include<iostream>
#include<cstring>
using namespace std; 

class fournisseur {
    protected :
        long id;
        char* raisonsociale;
        char* adresse;
        char* matricule ;
        float chiffreaff;
        char* groupe; 

    public:

        fournisseur (): id(0), chiffreaff(0){
            raisonsociale =NULL;
            adresse =NULL;
            matricule =NULL ;
            groupe =NULL;
            cout<<"constructeur sans parametre"<<endl;
        }

        fournisseur (int i, char* r, char* a, char*m, float ch, char* g) {
            try{
                if (id <= 0){
                throw (10);
                }
            }
            catch (int p){
                cout<<"erreur id <=0"<<endl;
                exit(-1); 
            }
            
            try{
                if (ch < 1000){
                throw (10.5);
                }
            }
            catch (float p){
                cout<<"erreur chiffre d'affaire < 1000"<<endl;
                exit(-1); 

            }
            
            id = i;
            chiffreaff =ch;

            raisonsociale = new char[strlen(r)+1];
            strcpy(raisonsociale, r);

            adresse = new char[strlen(a)+1];
            strcpy(adresse, a);

            matricule = new char[strlen(m)+1];
            strcpy(matricule, m);

            groupe = new char[strlen(g)+1];
            strcpy(groupe, g);
            
            cout<<"construucteur avec parametre"<<endl;

        }

        virtual ~fournisseur () {
            delete[] raisonsociale;
            delete[] adresse;
            delete[] matricule;
            delete[] groupe;
        }

        fournisseur (const fournisseur& f){
            id = f.id;
            chiffreaff = f.chiffreaff;

            raisonsociale = new char[strlen(f.raisonsociale)+1];
            strcpy(raisonsociale, f.raisonsociale);

            matricule = new char[strlen(f.matricule)+1];
            strcpy(matricule, f.matricule);

            adresse = new char[strlen(f.adresse)+1];
            strcpy(adresse, f.adresse);

            groupe = new char[strlen(f.groupe)+1];
            strcpy(groupe, f.groupe);
        }

        long get_id(){
            return id;
        }
        
        float get_ch(){
            return chiffreaff;
        }

        char* get_raisonsociale() {
            if (raisonsociale == NULL){
                return NULL;
            }
            char* r = new char[strlen(raisonsociale)+1];
            strcpy (r, raisonsociale);
            return r;
        }

        char* get_adresse() {
            if (adresse == NULL){
                return NULL;
            }
            char* r = new char[strlen(adresse)+1];
            strcpy (r, adresse);
            return r;
        }

        char* get_matricule() {
            if (matricule == NULL){
                return NULL;
            }
            char* r = new char[strlen(matricule)+1];
            strcpy (r, matricule);
            return r;
        }

        char* get_groupe() {
            if (groupe == NULL){
                return NULL;
            }
            char* r = new char[strlen(groupe)+1];
            strcpy (r, groupe);
            return r;
        }

        void set_id (long i){
            id =i;
        }

        void set_ch(float ch){
            chiffreaff = ch;
        }

        void set_raisonsociale(char* r) {
            raisonsociale = new char[strlen(r)+1];
            strcpy(raisonsociale, r);
        }

        void set_adresse(char* r) {
            adresse = new char[strlen(r)+1];
            strcpy(adresse, r);
        }

        void set_matricule(char* r) {
            matricule = new char[strlen(r)+1];
            strcpy(matricule, r);
        }

        void set_groupe(char* r) {
            groupe = new char[strlen(r)+1];
            strcpy(groupe, r);
        }

        virtual float get_ca_en_dinar() {
            return chiffreaff; 
        }

        virtual void view(){
            cout<<"affichage"<<endl;
            cout<<"id : "<<get_id()<<endl;
            cout<<"raison sociale : "<<get_raisonsociale() <<endl;
            cout<<"adresse : "<<get_adresse() <<endl;
            cout<<"matricule fiscal : "<<get_matricule ()<<endl;
            cout<<"chiffre d'affaire : "<<get_ch()<<endl;
            cout<<"groupe : "<<get_groupe()<<endl; 
        }

        fournisseur operator + (const fournisseur& B){
            try{
                if(this->matricule != B.matricule){
                    throw (10);
                }
                if (strcmp(groupe, B.groupe) !=0 ){
                    throw (100);
                }
            }
            catch (int p){
                if (p == 10) {
                    cout<<"erreur A et B n'ont pas le meme matricule fiscal "<<endl;
                    exit (-1);
                }
                else {
                    cout<<"erreur A et B n'ont pas le meme groupe "<<endl;
                    exit (-1);
                }
            }

            
            fournisseur *f= new fournisseur(id*10000L+B.id,groupe,matricule,chiffreaff+B.chiffreaff,groupe);
            return *f;
        }

};

class fournisseur_etranger : public fournisseur {
    private : 
        char* pays;
        char* devise;
        float cours; 
    public:
        fournisseur_etranger(int i, char* r, char* a, char*m, float ch, char* g, char* p, char* d, float c) : fournisseur (i,r,a,m,ch,g) , cours(c) {
            pays = new char[strlen(p)+1];
            strcpy (pays, p);

            devise = new char[strlen(d)+1];
            strcpy (devise, d);

            cout<<"constructeur etranger"<<endl;
        }

        ~fournisseur_etranger() {
            if (pays != NULL){
                delete[] pays;
            }

            if (devise != NULL){
                delete[] devise;
            }
        }

        float get_ca_en_dinar(){
            return chiffreaff*cours;
        }
};


