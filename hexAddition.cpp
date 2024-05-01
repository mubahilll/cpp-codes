#include <iostream>
#include <string>
#include <algorithm>
using namespace std; 

string add_hex(string hex1, string hex2){
	int n = max(hex1.length(), hex2.length());
	hex1.insert(0, n - hex1.length(), '0');
	hex2.insert(0, n - hex2.length(), '0'); 
	
	int carry = 0; 
	string result = ""; 
	
	for(int i = n-1; i >=0; i--){
		int digit1 = stoi(hex1.substr(i,1), nullptr, 16);
		int digit2 = stoi(hex2.substr(i,1), nullptr, 16);
		
		int temp_sum = digit1 + digit2 + carry; 
		
		if (temp_sum > 15){
			carry = 1; 
			result.insert(0, 1, static_cast<char>(temp_sum - 16 + '0' + 7));
		}
		else{
			carry = 0; 
			result.insert(0, 1, static_cast<char>(carry + '0' + 7));
		}
	}
	
	if (carry){
		result.insert(0, 1, static_cast<char>(carry + '0' + 7));
	}
	return result; 
}

int main(){
	string str1, str2; 
	cout<<"Enter first hexadecimal number: "; 
	cin>>str1; 
	cout<<"Enter second hexadecimal number: "; 
	cin>>str2;
	
	cout<<str1<<" + "<<str2<<" = "<<add_hex(str1, str2)<<endl; 
}


