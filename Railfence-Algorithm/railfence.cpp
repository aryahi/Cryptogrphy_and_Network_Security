# include <iostream>
# include <fstream>
# include <bits/stdc++.h>
using namespace std;

int main()
{
   int nrails, i, j, t, k, cnt = 0, skip, line, sk;
   string plain_txt, cipher_txt, ch, ct;
   cout<<"Enter number of rails : ";
   cin>>nrails;
  
   // GET DATA TO ENCRYPT
   cout<<"Enter data to encrypt : ";
   cin>>plain_txt;
   for(i = 0; i < plain_txt.length(); i++)
   {
	  if(plain_txt[i] == ' ')
	     {}
	  else
	     cnt++;
   }
   // ENCRYPTION
   if(nrails > ((2*cnt) - 1))
      cout<<"Key is too large for text"; 
   if(nrails == 1)
      cipher_txt = plain_txt; // IF KEY = 1 (PLAIN TEXT = CIPHER TEXT)
   else
   {
	  cipher_txt = "";
	  for(i = 0; i < nrails-1; i++)
	  {
	     sk = 2*(nrails-i-1);
		 j = 0;
		 for(t = i; t < cnt;)
		 {
			cipher_txt += plain_txt.at(t);
            if((i == 0) || (j%2 == 0))
			   t += sk;
			else  
			   t += 2*(nrails-1) - sk;
			j++;
		 }
	  }
      for(t = i; t < cnt; t += 2*(nrails-1))
		 cipher_txt += plain_txt.at(t);
   }
   // OUTPUT CIPHER TEXT
   cout<<"Cipher Text : "<<cipher_txt<<endl;
   
   cout<<"Decrypting cipher text : ";
   char pt[cnt];
   if(nrails > ((2*cnt) - 1))
      cout<<"Key is too large for text";

   // DECRYPTION
   k = 0;
   for(line = 0; line < nrails-1; line++)
   {
      skip = 2*(nrails-line-1);	 
	  j = 0;
      for(i = line; i < cnt;)
	  {
         pt[i] = cipher_txt.at(k++);
       	 if((line == 0) || (j%2 == 0)) 
		    i += skip;
         else 
			i+=2*(nrails-1) - skip;  
          j++;        
      }
   }
   for(i = line; i < cnt; i += 2*(nrails-1)) 
	  pt[i] = cipher_txt.at(k++);
	  
   // OUTPUT DECRYPTED PLAIN TEXT 
   for(i = 0; i < cnt; i++)
	  cout<<pt[i];
   cout<<endl;   
   return 0;
}
