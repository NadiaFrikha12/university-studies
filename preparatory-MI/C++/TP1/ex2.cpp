#include<iostream>
using namespace std;

void test(int n=0, float x=2.5) {
    cout<<"fonction \n" ;
	cout<<"n= "<< n<<"   x= "<< x<<endl;
}
		
int main(){
    int i=5; float r=3.2;
    test(i,r); // n=5   x=3.2
    test(r,i);  //n=3   x==5  => il a fait arrondi au floatpour le rendre int 
    test(i); //n=5   x=2.5  => il a utiliser la valeur de x dans l'argument de la fonction
    test(r); // n=3   x=2.5  => il a donné la valeur au premier parametre 
    test();  //n=0   x=2.5 
    test(i,i); // n=5   x=5
    test(r,r); // n=3   x=3.2

    return 1;
}
