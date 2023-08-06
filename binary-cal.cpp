#include <iostream>
#include <cmath>
using namespace std; 

void sub(){
    long a, b;
    int i = 0, r = 0, sub[20];
    cout << "1st number: ";
    cin >> a;

    cout << "2nd number: ";
    cin >> b;
    while (a != 0 || b != 0){
        sub[i++] = (a % 10 - b % 10 + r) % 2;
        r = (a % 10 - b % 10 + r) / 2;
        a = a / 10;
        b = b / 10;
    }
    if (r != 0){
        sub[i++] = r;
    }
    --i;
    cout << "Difference: ";
    while (i >= 0){
        cout << sub[i--];
    }
    cout << "\n"<<endl;
}

void sum(){
    long bn1,bn2;
	int i=0, r=0;
	int sum[20]; 
	cout << " Input the 1st binary number: ";
	cin>> bn1;
	cout << " Input the 2nd binary number: ";
	cin>> bn2;
    while (bn1 != 0 || bn2 != 0) {
        sum[i++] = (int)((bn1 % 10 + bn2 % 10 + r) % 2);
        r = (int)((bn1 % 10 + bn2 % 10 + r) / 2);
        bn1 = bn1 / 10;
        bn2 = bn2 / 10;
    }
    if (r != 0) {
        sum[i++] = r;
    }
    --i;
    cout<<" The sum of two binary numbers is: ";
    while (i >= 0) {
        cout<<sum[i--];
    }
    cout<<"\n"<<endl; 
}

int dectoBin(int n){
    int dec = 0;
    int rem, i = 1;

    while(n!=0){
        rem = n % 2;
        dec += rem*i;
        i = i * 10;
        n = n / 2;
    }
    cout<<"Binary: "<<dec<<endl<<endl; 
}

int bintoDec(int bin){
    int dec = 0, rem, base = 0;
	while (bin != 0){
		rem = bin%10; 
		bin /= 10; 
		dec += rem * pow(2, base); 
		base++; 
	}
	
	cout<<"Decimal: "<<dec<<endl<<endl; 
}

int main(){
    int op, num;  
    char ch;
  
    cout<<"select conversion\n1-Decimal to Binary\n2-Binary to Decimal\n3-Add two binary numbers\n4-subtract two binary numbers\n0-Quit\n--Option: ";
    cin>>op; 

    switch(op){
        case 1: 
            cout<<"\nEnter decimal number: "; 
            cin>>num; 
            dectoBin(num);
            break; 
        case 2: 
            cout<<"\nEnter binary number: "; 
            cin>>num; 
            bintoDec(num); 
            break; 
        case 3:
            cout<<endl;
            sum();
            break; 
        case 4:
            cout<<endl;
            sub();
            break;
    }
}