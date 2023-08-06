#include <iostream>
#include <cmath>
using namespace std; 
int main(){
	int bin, dec = 0, rem, base = 0;
	cout<<"Enter any binary number: "; 
	cin>>bin; 
	 
	while (bin != 0){
		rem = bin%10; 
		bin /= 10; 
		dec += rem * pow(2, base); 
		base++; 
	}
	
	cout<<"Decimal: "<<dec<<endl; 
}
