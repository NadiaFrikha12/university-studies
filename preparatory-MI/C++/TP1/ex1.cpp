#include<iostream>
using namespace std; 
#define pi 3.14

int main(){
    float r, surface;
    cout<<"donner le rayon du cercle"<<endl;
    cin >> r;
    surface = pi*r*r;
    cout << "la surface du cercle est ="<< surface<<endl;
    return 0;
}