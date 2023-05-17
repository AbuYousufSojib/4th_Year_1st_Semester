#include <bits/stdc++.h>
using namespace std;
int main()
{
     string plaintext,ky,key="";
     cout<<"Enter your message and key: ";
     cin>>plaintext>>ky;
     //processing plaintext length equal to key by repeating
     for(int i=0;i<plaintext.size();i++)
     {
          key+=(ky[i%ky.size()]);
     }
     cout<<"Plaintext :"<<plaintext<<endl<<"Requirekey:"<<key<<endl;
     map<char,int>letter;
     map<int,char>inttochar;
     for(int i=0;i<26;i++)
     {
        letter.insert({char('A'+i),i});//char key
        inttochar.insert({i,char('A'+i)});

     }

     //Encryption part
      string encrypt="";
      vector<int> v;
     for(int i=0;i<key.size();i++)
     {
       int ans = (letter[plaintext[i]]^letter[key[i]]);
       v.push_back(ans);
       encrypt+=inttochar[ans%26];
       bitset<5> bin(letter[plaintext[i]]);
       bitset<5>kyn(letter[key[i]]);
       bitset<5>res(ans%26);
       //cout<<bin<<" xor "<<kyn<<" is :-> "<<inttochar[ans%26]<<endl;
       cout<<plaintext[i]<<"("<<bin<<")"<<" xor "<<key[i]<<"("<<kyn<<")"<<" is :-> "<<inttochar[ans%26]<<"("<<res<<")"<<endl;
     }

     cout<<"Encrypted Text is :"<<encrypt<<endl;
     //Decryption part
     string decrypt="";
     for(int i=0;i<encrypt.size();i++)
     {
       int ans = (letter[key[i]]^v[i]);
       //cout<<ans<<endl;
       bitset<5> kyn(letter[key[i]]);
       bitset<5>bin(v[i]);
       bitset<5>res(ans);
       decrypt+=inttochar[ans];
       cout<<encrypt[i]<<"("<<kyn<<")"<<" xor "<<key[i]<<"("<<bin<<")"<<" is :-> "<<inttochar[ans]<<"("<<res<<")"<<endl;
     }
     cout<<"Decrypted Text is :"<<decrypt<<endl;

    return 0;}


