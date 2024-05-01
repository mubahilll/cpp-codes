#include <iostream>
using namespace std;
int main ()
{
	//prime number
	
	int x;
	cin>>x;
	int i;
	bool flag=true;
	for (i=2; i<x; i++ )
	{
		if (x%i==0)
		{
			cout<<"Non prime";
			flag=false;
			break;
		}
	}
	if (flag){
		cout<<"Prime Number";
	}
	
	return 0;
}

