
# include <iostream>

using namespace std;

//	MODULE TO FIND GCD
int gcd(int n, int m)
{
   int q;
   q = n%m;

if(q == 0)
	return m;
else
	return gcd(m, q);
}

int main()
{
   int n, m, z;
   cout<<"Enter two integers : ";
   cin>>n>>m;
   z = gcd(n, m);
   cout<<"GCD : "<<z<<endl;;
   return 0;
}
