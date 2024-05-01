#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int x, rev=0;
	cin>>x;
	while (x>0){
		int lastdigit = x%10;
		rev = rev*10 + lastdigit;
		x/=10;
	}
	cout<<rev;
	return 0;
}

