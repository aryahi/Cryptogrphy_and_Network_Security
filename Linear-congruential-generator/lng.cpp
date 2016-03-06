# include <iostream>
# include <string.h>
# include <cmath>
using namespace std;
int main()
{
	long long i, a = pow(7, 5), b = 0, n = pow(2, 31)-1, xo = 9;
	char c;
	while(1)
	{
		xo = ((a*xo)+b)%n;
		cout<<xo<<endl;
		cout<<"Enter y to generate random number and n otherwise : ";
		cin>>c;
		if(c == 'n')
			break;
		
	}
	return 0;
}
