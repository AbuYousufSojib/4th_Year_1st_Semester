#include <bits/stdc++.h>
using namespace std;

int main()
{
 
	 string s;
	 cin.ignore();
	 getline(cin,s);
         int key;
         cin>>key;
         key%=26;
         string dstr ="";

     for(int i=0;s[i];i++)
     {
       
       if(s[i] >=97 and s[i] <= 122)
       {
   		dstr+= (s[i] - key) < 97 ? char((s[i] - key)+26): char(s[i] - key) ;
       }

       else if(s[i] >=65 and s[i] <= 90)
       {
   		dstr+= (s[i] - key) < 65 ? char((s[i] - key)+26): char(s[i] - key) ;
       }

       else if(s[i] >= 48 and s[i] <= 57)
       {
       	dstr+= (s[i] - key) < 48 ? char((s[i] - key)+9): char(s[i] - key) ;
       }

       else dstr+=s[i];

     }
        cout<<dstr<<endl;
      
	return 0;
}
