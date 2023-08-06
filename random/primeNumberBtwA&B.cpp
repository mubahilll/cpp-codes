
#include <iostream>
using namespace std;
int main ()
{
	int x,y,rem, res;
	cin>>x;
	y=x;
	
	while (x!=0){
		rem = x%10;
		res = res+rem*(rem*rem); 
		x/=10;
	}
	
	if (res==y){
		cout<<"arm";
	}
	else
	cout<<"narm";
	return 0;
}

