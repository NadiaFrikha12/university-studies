#include<iostream>
using namespace std;

class volante {
    protected :
        int nb_ailes;
    public : 
        volante (int nb=0):nb_ailes(nb){
            cout<<"constructuer volante"<<endl;
        }

        virtual void affiche(){
            cout <<"nombre ailes : "<<nb_ailes<<endl;
        }

        virtual ~volante() {
            cout<<"destructuer volante"<<endl;

        } 

};

class animal {
    protected : 
        int nb_pattes;
        char* type_pelage; 
    public: 
        animal (int nb, char* s): nb_pattes(nb), type_pelage(s){
            cout<<"constructeur animal"<<endl;
        }

        virtual void affiche(){
            cout <<"nombre pattes : "<<nb_pattes<<endl;
            cout <<"type pelage : "<<type_pelage<<endl;

        }

        virtual ~animal() {
            cout<<"destructeur animal"<<endl;
        } 
};

class oiseau : public volante, public animal {
    private :
        int nb_oeufs; 
    public :
        oiseau (int nba, int nbp, char*s , int nbo) : volante(nba), animal (nbp,s), nb_oeufs(nbo) {
            cout<<"constructeur oiseau"<<endl;
        }

        void affiche() override {
            volante::affiche();
            animal::affiche();
            cout<<"nombre des oeufs : "<<nb_oeufs<<endl;
        }

        ~oiseau(){
            cout<<"desstructeur oiseau"<<endl;

        }
};

int main (){
    oiseau o(2,2,"oiseau",4);
    o.affiche();

}
