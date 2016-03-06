/*
# include <iostream>
# include <string>
# include <cmath>
using namespace std;

//	RSA
int power(long long int a, long long int b, long long int M)
{
   long long int ret = 1;
   while(b)
   {
	  if(b % 2 == 1)
	     ret = (ret*a)%M;
 	  a = (a*a)%M;
	  b /= 2;
   }
 return ret%M;
}
int gcd(int n, int m)
{
   int q;
   q = n%m;

	if(q == 0)
		return m;
	else
		return gcd(m, q);
}

int co_prime1(long long int no)
{
	int i, d;
	for(i = 2; i < (no/2); i++)
	{
		d = gcd(i, no);
		if(d == 1)
			return i;
	}
}

int modInverse(int a, int m)
{
	int i;
	a = a%m;
	for(i = 1; i < m; i++)
		if((a*i)%m == 1)
			return i;
}

int main()
{
	long long int p, q, n, no, d, num, e;
	char c;
	string str;
	cout<<"Enter p and q : ";
	cin>>p>>q;
	n = (p*q);
	cout<<"n : "<<n<<endl;
	no = ((p-1)*(q-1));
	cout<<"no : "<<no<<endl;
	e = co_prime1(no);
	//e = 13;
	cout<<"e : "<<e<<endl;
	d = modInverse(e, no);
	cout<<"d : "<<d<<endl;
	cout<<"Enter n to encode number : ";
	cin>>c;
	if(c == 's' || c == 'S')
	{
		cout<<"Enter string to encode ; ";
		cin>>str;
	}
	else if(c == 'n' || c == 'N')
	{
		long long int ct = 0, pt = 0;
		cout<<"Enter number to encode : ";
		cin>>num;
		ct = power(num, e, n) ;
		//ct = ct%n;
		cout<<"Cipher text : "<<ct<<endl;
		pt = power(ct, d, n);
		//pt = pt%n;
		cout<<"Plain text : "<<pt<<endl;
	}
	else
	{
		cout<<"Wrong choice"<<endl;
	}
	return 0;
}
*/








# include <iostream>
# include <string>
# include <cmath>
using namespace std;

//	RSA

// HANDLING EXPONENTIAL PART 
int power(long long int a, long long int b, long long int M)
{
   long long int ret = 1;
   while(b)
   {
	  if(b % 2 == 1)
	     ret = (ret*a)%M;
 	  a = (a*a)%M;
	  b /= 2;
   }
 return ret%M;
}

// FINDING GCD USING EUCLIDEAN METHOD
int gcd(int n, int m)
{
   int q;
   q = n%m;

	if(q == 0)
		return m;
	else
		return gcd(m, q);
}

//	CHECKING COPRIME
int co_prime1(long long int no)
{
	int i, d;
	for(i = 2; i < (no/2); i++)
	{
		d = gcd(i, no);
		if(d == 1)
			return i;
	}
}

//	FINDING MODULO INVERSE OF NUMBER
int modInverse(int a, int m)
{
	int i;
	a = a%m;
	for(i = 1; i < m; i++)
		if((a*i)%m == 1)
			return i;
}

// DETERMINISTIC METHOD TO CHECK IF NUMBER IS PRIME
int chk_prime(long long int n)
{
	long long int i;
	for(i = 2; i < (n/2); i++)
	{
		if(n%i == 0)
			return 0;
	}
	return 1;
}

// GENERATING RANDOM NUMBER
int random_num()
{
	long long chk, i, a = pow(7, 2), b = 13, n = pow(2, 11), xo;
	char c;
	while(1)
	{
		xo = ((a*xo)+b)%n;
		cout<<xo<<endl;
		chk = chk_prime(xo);
		if(chk == 0)
			cout<<"Composite\n";
		else
			cout<<"Prime\n";
		cout<<"Enter y to generate random number and n otherwise : ";
		cin>>c;
		if(c == 'n')
		{
			return xo;
			break;
		}		
	}
}

int main()
{
	long long int p, q, n, no, d, num, e;
	long long int y;
	char c;
	string str;
   
   // FINDING VALUE OF P AND Q
   cout<<"Finding p"<<endl;
	p = random_num();
	cout<<"Finding q"<<endl;
	q = random_num();

   cout<<"p : "<<p<<endl;
   cout<<"q : "<<q<<endl;
   
   // CALCULATING N
	n = (p*q);
	cout<<"n : "<<n<<endl;
	
	// FINDING TOTIENT FUNCTION OF N
	no = ((p-1)*(q-1));
	cout<<"no : "<<no<<endl;
	
	// FINDING E (COPRIME TO TOTIENT OF N)
	e = co_prime1(no);
	//e = 13;
	cout<<"e : "<<e<<endl;
	
	// FINDING D - PRIVATE KEY
	d = modInverse(e, no);
	cout<<"d : "<<d<<endl;
	cout<<"Enter n to encode number : ";
	cin>>c;
	
	// ENCODING AND DECODING INTEGERS
	if(c == 'n' || c == 'N')
	{
		long long int ct = 0, pt = 0;
		cout<<"Enter number to encode : ";
		cin>>num;
		ct = power(num, e, n) ;
		//ct = ct%n;
		cout<<"Cipher text : "<<ct<<endl;
		pt = power(ct, d, n);
		//pt = pt%n;
		cout<<"Plain text : "<<pt<<endl;
	}
	else
	{
		cout<<"Wrong choice"<<endl;
	}
	return 0;
}
