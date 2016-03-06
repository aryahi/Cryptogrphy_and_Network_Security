
# include <iostream>
using namespace std;

// CHECKING IF GCD == 1
int gcd(int n, int m)
{
   int q;
   q = n%m;

if(q == 0)
	return m;
else
	return gcd(m, q);
}

// CHECKING IF MOD m1, m2...mn ARE REALTIVELY PRIME
int chk_rlt_prime(int n[], int s)
{
	int i, j;
	cout<<"Inside\n";
	for(i = 0; i < s; i++)
	{
		for(j = i+1; j < s; j++)
		{
			cout<<n[i]<<"\t"<<n[j]<<endl;
			if(gcd(n[i], n[j]) != 1)
				return 0;
		}
	}
	return 1;
}

// USING EXTENDED EUCLIDEAN ALGORITHM TO FIND INVERSE
int ext_euc(int n, int m, int t1, int t2)
{
   int q;
   int s, t;
   int y = (n/m);
   t = t1 - (y*t2);
   q = n%m;

   if(q == 0)
   {
     //cout<<"t = "<<t2<<endl;
     return t2;	
   }
   else
   {
      t1 = t2; t2 = t;
	   return ext_euc(m, q, t1, t2);
   }
   return 0;
}

int main()
{
	int s, i, M = 1, x;
	cout<<"Enter number of equations : ";
	cin>>s;
	int a[s], n[s], m[s], mi[s];
	
	// ENTER VALUE OF a AND n
	cout<<"Enter value of a and n :\n";
	for(i = 0; i < s; i++)
		cin>>a[i]>>n[i];
		
	// CALCULATE M = n1*n2*n3.....*nn
   for(i = 0; i < s; i++)
   	M = M*n[i];
   cout<<"M = "<<M<<endl;	
   
   // CHECK IF X EXISTS USING RELATIVE PRIME CONDITION	
	int d = chk_rlt_prime(n, s); 
	cout<<d<<endl;
	if(d == 0)
	{
		cout<<"All n are not relatively prime, hence x cannot be found\n";
	} 
	else
	{
		cout<<"X can be found\n";
		// FINDING M AND (1/M)%N
		for(i = 0; i < s; i++)
		{
			m[i] = M/n[i];
			mi[i] = ext_euc(n[i], m[i], 0, 1);
			
			if(mi[i] < 0)
			{
				mi[i] = n[i] + mi[i];
				mi[i] = mi[i]%n[i];
			}
		
		}
		//	PRINTING M AND M_INVERSE
		cout<<"M and M inverse\n";
		for(i = 0; i < s; i++)
		{
			cout<<m[i]<<"\t"<<mi[i]<<endl;
		}
		// FINDING X
		cout<<"Finding x\n";
		x = 0;
		for(i = 0; i < s; i++)
		{
			x = x + a[i]*m[i]*mi[i];
		}
		cout<<"X = "<<(x%M)<<endl;
	}
	return 0;
}
