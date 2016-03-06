# include <iostream>
# include <iomanip>
using namespace std;

// PUTTING FLAGS IN TABLE
int chk(char table[5][5], char k)
{
   int i, j;
   for(i = 0; i < 5; i++)
   {
	  for(j = 0; j < 5; j++)
	  {
		 if(table[i][j] == k)
			return 0;
	  }
   }
   return 1;
}

// DECRYPTION MODULE TO DECRYPT CIPHER TEXT
void decode(char table[5][5], char a, char b)
{
   int i, j, c, d, e, f;
   
   for(i = 0; i < 5; i++)
   {
	  for(j = 0; j < 5; j++)
	  {
		 if(a == table[i][j])
		 {
			c = i; d = j;
		 }
		 if(b == table[i][j])
		 {
			e = i; f = j;
		 }
	  }
   }
   if(c == e)
   {
	  cout<<table[c][(d+5)%5]<<table[c][(f+5)%5]<<endl;
   }
   else if(d == f)
   {
	  cout<<table[(c-1)%5][d]<<table[(e-1)%5][d]<<endl;
   }
   else
   {
	  cout<<table[c][f]<<table[e][d]<<endl;
   }
}

// ENCRYPTION MODULE TO ENCRYPT PLAIN TEXT
char encode(char table[5][5], char a, char b)
{
   int i, j, c, d, e, f;
   char w1, w2;
   for(i = 0; i < 5; i++)
   {
	  for(j = 0; j < 5; j++)
	  {
		 if(a == table[i][j])
		 {
			c = i; d = j;
		 }
		 if(b == table[i][j])
		 {
			e = i; f = j;
		 }
	  }
   }
   if(c == e)
   {
      w1 = table[c][(d+4)%5]; w2 = table[e][(f+4)%5];
	  cout<<table[c][(d+6)%5]<<table[e][(f+6)%5]<<"\t\t";
   }
   else if(d == f)
   {
	  w1 = table[(c+6)%5][d]; w2 = table[(e+6)%5][f];
	  cout<<table[(c+6)%5][d]<<table[(e+6)%5][f]<<"\t\t";
   }
   else
   {
	  w1 = table[c][f]; w2 = table[e][d];
	  cout<<table[c][f]<<table[e][d]<<"\t\t";
   }
   decode(table, w1, w2);
}


int main()
{
   string str, str1, str3;
   int i, j;
   cout<<"Enter keyword : ";
   cin>>str;
   cout<<"Enter Text : ";
   cin>>str1;
   j = 0;
   
   // INITIALISING TABLE WITH ALL 0'S
   char table[5][5];
   for(i = 0; i < 5; i++)
   {
	  for(j = 0; j < 5; j++)
	  {
		 table[i][j] = '0';
	  }
   }
   //	LENGTGH AND FLAGS IN KEYWORD ARRAY TO AVOID REPITITION
   int t = str.length();
   int flag[t];
   for(i = 0; i < t; i++)
   	  flag[i] = 1;
   for(i = 0; i < t; i++)
   {
	  if(str[i] == ' ')
		 flag[i] = 0;
   }
   for(i = 0; i < t; i++)
   {
      for(j = i+1; (j < t) && (flag[i] != 0); j++)
	  {
		 if(str[i] == str[j]) 
         {
			flag[j] = 0;
		 }
	  }
   }
   i = 0;int n = 0;

   // INSERTING KEYWORD IN TABLE
   for(j = 0;n < t; n++)
   { 
	  if(j%5 == 0 && (j != 0))
	  {
		 j = 0;
	     i++;
		 n = n-1;
	  }
      else if(flag[n] != 0)
      {
		 if(str[n] == 'i')
		 {
			char kl = str[n]+1;
			table[i][j] = kl;
			j++;
		 }
		 else
		 {
		    table[i][j] = str[n];
		    j++;
		 }
	  }
   }

   char a = 97;
   int p = 0, l = 0, flag1 = 0;
   // CREATING FULL FINAL TABLE
   for(i = 0; i < 5; i++)
   {
	  for(j = 0; j < 5; j++)
	  {
		 if(table[i][j] == '0')
		 {  
			if(chk(table, a) == 1)
			{
			   if(a == 'i')
			   {
				  if(chk(table, a+1) == 1)
				  {
					 table[i][j] = a;
					 a=a+2;
				  }	
				  else
				  {
					 a = a+2;j = j-1;
				  }
			   }
			   else
			   {
			      table[i][j] = a;
			      a++; 
			   }
			}
			else
			{  
			   j = j-1;
			   a++;
			}
		 } 
	  }
   }

   // PRINTING FULL TABLE
   for(i = 0; i < 5; i++)
   {
	  for(j = 0; j < 5; j++)
	  {
		 cout<<table[i][j]<<"\t";
	  }
	  cout<<endl;
   }
   
   i = 0; j = 0;
   // REMOVING SPACES FROM TEXT
   while(str1[i])
   {
	  if(str1[i] != ' ')
      {
         str1[j++] = str1[i];
      }
	  i++;
   }
   str1[j] = '\0';
  
   int y = str1.length();
   string pl_txt;
   
   // CREATING DIGRAPH
   cout<<"Digraph : ";
   char c; char b, d, e, f;i = 0;
   while(str1[i])
   {
	  b = str1[i]; c = str1[i+1];
      if((i == str1.length()-1) && (str1.length() % 2 != 0))
 	  {
		 c = 'x';
	  }
      if(str1[i] == str1[i+1])
	  { 
		 c = 'x'; 
         cout<<b<<c<<"\t";
		 d = str1[i+2]; e = str1[i+3];
	     if(str1[i+2] == str1[i+3])
		 {
			cout<<b<<d<<"\t";
			e = 'x';
			cout<<d<<e<<"\t";
			i = i+4;
		 }
		 else
		 {
			i = i+2;
		 }
	  }
	  else
      {
		 cout<<b<<c<<"\t";//cout<<"a4"<<"\t";
		 i = i+2;
	  }  
   } 
   cout<<endl;
   
   // CREATING BLOCKS OF CIPHER TEXT
   cout<<"Ci_Text : Plain_txt"<<endl;
   i = 0;
   while(str1[i])
   {
	  b = str1[i]; c = str1[i+1];
      if((i == str1.length()-1) && (str1.length() % 2 != 0))
		 c = 'x';
      if(str1[i] == str1[i+1])
	  { 
		 c = 'x'; 
		 encode(table, b, c);
		 d = str1[i+2]; e = str1[i+3];
	     if(str1[i+2] == str1[i+3])
		 {
		    encode(table, b, d);
			e = 'x';
			encode(table, d, e);
			i = i+4;
		 }
	     else{ i = i+2;}
	  }
	  else
      {
		 encode(table, b, c);
		 i = i+2;
	  }
   } 
   cout<<endl;
   
   return 0;
}
