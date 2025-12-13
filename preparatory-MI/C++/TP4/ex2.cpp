#include<iostream>
using namespace std;

class point { 								
    protected : 							
        int x,y ; 							 
    public :    
        //constructeur                                   
        point (int a=0, int b=0) : x(a) , y(b) {}		

        void affiche(){
            cout<<"x= "<<x<<endl;
            cout<<"y= "<<y<<endl;
        }					

        //qui affiche l’entier int et le point
        void affiche(int a){
            cout<<"entier  : "<<a<<endl;
            affiche();
        } 		      
}; 								

class pointcol : public point {
    private :
        int color;
    public :
        //constructeur 
        pointcol (int a, int b , int c) : point(a,b), color(c){}
        void affiche(){
            cout<<"x = "<<x<<endl;
            cout<<"y = "<<y<<endl;
            cout<<"color = "<<color<<endl;

        }
        using point::affiche; // Rendre affiche(int) accessible dans pointcol

};

int main(){
    pointcol p(1,2,3);
    p.affiche(2);

    return 0;
}