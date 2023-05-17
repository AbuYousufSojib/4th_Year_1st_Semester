#include <bits/stdc++.h>
using namespace std;
int main()
{
     string plaintext,key,ky;
     cout<<"Enter your plain-text and key: ";
     cin>>plaintext>>ky;
    for(int i=0;i<plaintext.size();i++)
     {
          key+=(ky[i%ky.size()]);
     }
     cout<<key<<endl;
     //For encryption
     string encrypt="";
     for(int i=0;plaintext[i];i++){
        //formula use ci=(pi+ki)%26
        encrypt+=char('a'+((plaintext[i]-'a'+key[i]-'a'))%26);
        cout<<plaintext[i]<<" and "<<key[i]<<" encrypted is :->"<<char('a'+((plaintext[i]-'a'+key[i]-'a'))%26)<<endl;
               }
        cout<<"\nFinally Encrypted output is: "<<encrypt<<endl;
     //For decryption
        string decrypt="";
         for(int i=0;encrypt[i];i++)
       {
        int ans=encrypt[i]-key[i];
        if(ans<0)ans+=26;
        decrypt+=char('a'+ans);
        cout<<encrypt[i]<<" and "<<key[i]<<" decrypted is :->"<<char('a'+ans)<<endl;
       }
        cout<<"\nFinally Decrypted output is: "<<decrypt<<endl;
    return 0;}


