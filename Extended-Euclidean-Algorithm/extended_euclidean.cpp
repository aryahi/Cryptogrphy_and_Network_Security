
# include <iostream>

using namespace std;

// MODULE TO FIND EXTENDED EUCLIDEAN
int ext_euc(int n, int m, int s1, int s2, int t1, int t2)
{
   int q;
   int s, t;
   int y = (n/m);
   s = s1 - (y*s2); 
   t = t1 - (y*t2);
   q = n%m;

   if(q == 0)
   {
	  cout<<"gcd = "<< m<<"\ns = "<<s2<<"\nt = "<<t2<<endl;	
   }
   else
   {
      s1 = s2; s2 = s; t1 = t2; t2 = t;
	  return ext_euc(m, q, s1, s2, t1, t2);
   }
   return 0;
}

int main()
{
   int n, m, z;
   cout<<"Enter two integers : ";
   cin>>n>>m;
   ext_euc(n, m, 1, 0, 0, 1);

   return 0;
}
