#include <bits/stdc++.h>
using namespace std;

int main()
{
	
	 string s;
	 getline(cin,s);
         int key;
         cin>>key;
         key%=26;
         string dstr ="";
     for(int i=0;s[i];i++)
     {
        
       if(s[i] >=97 and s[i] <= 122)
       {
   		dstr+= (s[i] + key) > 122 ? char('a'+(s[i] + key)%122): char((s[i] + key)) ;
       }

       else if(s[i] >=65 and s[i] <= 90)
       {
   		dstr+= (s[i] +key) > 90 ? char(('A'+s[i] + key) % 90): char((s[i] + key));
       }
       else if(s[i] >= 48 and s[i] <= 57)
       {
       	dstr+= (s[i] + key) > 57 ? char(('0'+s[i] + key)%58): char(s[i] + key) ;
       }
       else dstr+=s[i];

     }
     cout<<dstr<<endl;
      
	return 0;
}
