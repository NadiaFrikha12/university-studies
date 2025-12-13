#include<iostream>
using namespace std;

class ensemble{
    private: 
        int n;
        int *t;
    public: 


        void definir(int n){
            if (t !=NULL){
                delete[] t; 
            }
            t= new int[this->n =n ];
        }

        ensemble remplir() {
            for (int i =0 ; i<n ; i++){
                cin >> t[i];
            }
        }

        void intersection (ensemble e){
            
        }

};