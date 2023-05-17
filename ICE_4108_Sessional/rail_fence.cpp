#include <bits/stdc++.h>
using namespace std;
int main()
{
    string plaintext,key;
    cout<<"Enter your plain-text and key: ";
    cin>>plaintext>>key;

    int rem = key.size()-plaintext.size()%key.size();
    //out<<rem<<endl;
    string barti;
    for (int i = 0; i < rem; ++i)
    {
        barti+='a'+(26-rem+i);
    }

    plaintext+=barti;                        //barti ta milanur jonno korlam.
    //cout<<plaintext<<endl;
    //cout<<plaintext.size()<<endl;
    map<int,vector<char> > mp;    //column vabe store korar jonno korlam.

    cout<<"Key is : "<<key<<"\nPlaintext: "<<endl;
    cout<<plaintext<<"\nMatrix is :\n"<<endl;

    //for matrix show key wise
    for (int i = 0; i < plaintext.size(); i+=key.size())

    {
          for(int j=0;j<key.size();j++)
          {
            mp[(key[j]-'0')].push_back(plaintext[i+j]);
            cout<<plaintext[i+j]<<" ";
          }
          cout<<endl;
    }

    //final output for rail fence cipher technique
   cout<<endl<<endl;
       string encryp="";
     for(auto it:mp)
     {
        for (int i = 0; i < it.second.size(); ++i)
        {
            encryp+=char((it.second[i]));
        }
        //cout<<endl;

     }

     cout<<"Encryption is : "<<encryp<<endl;

     ///-------Decryption part-------///
     map<int, vector<char> > demp;

      int k=1; //for map index
      int len=plaintext.size()/key.size();
      for (int i = 0; i < encryp.size(); i+=len)

    {
         vector<char>temp;
          for(int j=0;j<len;j++)
          {
            temp.push_back(encryp[i+j]);
          }
          demp[k]=temp;
          k++;
    }

     cout<<"Decryption matrix----\n\n";
     for(int j=0;j<key.size();j++){

        for(int i=0;i<demp[key[j]-'0'].size();i++)
        {
           cout<<demp[key[j]-'0'][i]<<" ";
        }
        cout<<endl;
            }
        string decryp="";
        cout<<"Decryption Reverse matrix is :"<<endl;
        for(int k=0;k<encryp.size()/key.size();k++){
        for(int j=0;j<demp.size();j++)
        {

            cout<<demp[key[j]-'0'][k]<<" ";
            decryp+=demp[key[j]-'0'][k];
        }
        cout<<endl;
       }
       cout<<"Decryption text is : "<<endl;
       cout<<decryp<<endl;
    return 0;
}
