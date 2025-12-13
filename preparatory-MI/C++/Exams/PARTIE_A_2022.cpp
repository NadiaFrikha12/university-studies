#include<iostream>
#include<cstring>
using namespace std;

class composant{
    private :
        int id;
        char* libelle;

    public : 

        composant(): id(0){
            libelle = NULL;
        }

        composant (int i, char* b){
            id = i;
            libelle = new char[strlen(b) +1];
            strcpy(libelle, b);
        }

        composant (const composant& c){
            id = c.id;
            libelle = new char[strlen(c.libelle) +1];
            strcpy(libelle, c.libelle);
        }

        ~composant (){
          if (libelle){
            delete[] libelle;
          }  
        }

        operator char* (){
            char s[100];
            sprintf(s,"id : %d, libelle :%s", id , libelle)
        }

        //convertir un objet de la classe en char* 
        //donc on peut utiliser cout *this 
};