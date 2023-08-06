#include <iostream>
#include <cmath>
using namespace std; 

int main(){
    int dec, rem, i = 1;
    long bin = 0; 
    cout<<"Enter decimal number: ";
    cin>>dec;

    while(dec != 0){
        rem = dec % 2;
        bin += rem*i; 
        i *= 10; 
        dec /= 10;
    }

    cout<<"Binary: "<<bin<<endl; 
}