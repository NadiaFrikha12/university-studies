#include<iostream>
using namespace std;

float puissance( float x, int n){
    cout<<"fonction puissance \n";
    float p=1;
    for( int i =0 ; i<n ;i++){
        p *= x;
    }
    return p;
}

int main(){
    float p = puissance (2,4.2);
    cout<< "puissance = "<< p<<endl;
    return 0; 
}