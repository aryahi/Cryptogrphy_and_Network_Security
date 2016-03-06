# include <iostream>
# include <fstream>
# include <string>
# include <bitset>
# include <cstdio>

using namespace std;

int main()
{
   fstream input, output;
   input.open( "/home/himani/iss/in.txt");
   output.open("/home/himani/iss/out.txt");

   string in, line, line1;
   int i, t, k ,j , y, l = 0, cnt = 0;
   
   cout<<"Enter string to encode : ";
   getline(cin, in);
   t = in.length();
   int arr[8*t], arr1[8*t];

	// CHAR TO ASCII
   for(i = 0; i < in.length(); i++)
   {
	  char x = in.at(i);
	  k = l;

	  y = int(x);
     cout<<y<<endl;
     for(j = 8; j > 0; j--)
	  {
		 arr[k] = y%2;
	 	 y = y/2;
		 k++;
	  }
	  l = k;
   }
   
   k = 0;
   // HIDING PLAIN TEXT IN FILE
   // 1 == DOUBLE SPACE
   // 0 == SINGLE SPACE
   while(getline(input, line))
   {
	  for(i = 0; i < line.length() ; i++)
      {
	     output<<line[i];
		 if(line[i] == ' ')
	 	 {   
			if(arr[k] == 1) 		
			{
			   output<<" ";
			}
			k++;
		 }
	  }
   }

   output.close();
   output.clear();

   string d;
   k = 0;
   
   // OPENING OUTPUT FILE
   output.open("/home/himani/iss/out.txt");

 	// CONVERTING SPACES IN OUTPUT FILE TO BITS
   while(getline(output, line1))
   {
      for(i = 0; i < line1.length(); i++)
      {    		
		 if(line1[i] == ' ')
	 	 {
            if( k == 8*t)
				break;
			if(line1[i+1] == ' ')
			{
				arr1[k] = 1;
				i = i+1;
				//cout<<"arr1[k]"<<" "<<arr1[k]<<" "<<k<<endl;
			} 
			else
			{
				arr1[k] = 0;
			    //cout<<"arr1[k]"<<" "<<arr1[k]<<" "<<k<<endl;
			}
			k++;
		 }	
	  }
   }

   cout<<"Data is hidden in file out.txt"<<endl;

	// GROUP OF BITS TO ASCII
   int arr2[t], sum, p = 0;
   for(i = 0; i < t; i++)
   {
      arr2[i] = 0;j = p;
      for(j = p+7; j >= p; j--)
      {	
		 sum = 1;
	     if(arr1[j] == 0)
	     {
		    arr2[i] += 0;
	     }
	     else
	     {
		    for(l = 0; l < (j%8); l++)	
		    {
			   sum = sum * 2;
		    }
		    arr2[i] = arr2[i] + sum;
	     }
      }
      p = j+9;
   }

	// ASCII TO CHARACTER
   cout<<"Decoded string : ";

   for(i = 0; i < t; i++)
   {
      d[i] = arr2[i];
      cout<<d[i];
   }
   cout<<endl;
   return 0;
}
