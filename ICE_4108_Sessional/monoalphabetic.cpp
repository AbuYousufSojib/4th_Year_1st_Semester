#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<char, int>& a,pair<char, int>& b)
{
    return a.second >= b.second;
}
int main()
{
     string frequency="ETAOINSRHLDCUMFPGWYBVKXJQZ";
     string plaintext;
     cout<<"Enter your plain-text: ";
     cin>>plaintext;
     vector<pair<char, int> > v;
     map<char,int>mp;
     for(int i=0;plaintext[i];i++)
     {
        mp[plaintext[i]]++;
     }
    // for(auto it:mp)cout<<it.first<<" "<<it.second<<endl;
     for(auto it:mp)v.push_back(it);
        sort(v.begin(),v.end(),cmp);
     for(auto it:v)cout<<it.first<<" "<<it.second<<endl;
    map<char,char>letter;
    map<char,char>dec;
    int i=0;
    map<char,int>asc;
    for(auto it:v)
    {
        letter.insert({it.first,frequency[i]});
        dec.insert({frequency[i],it.first});
        i++;
    }
    //For encrypted part
    string encrypt="";
    for(int i=0;plaintext[i];i++)
    {
        encrypt+=letter[plaintext[i]];
        cout<<plaintext[i]<<" encrypted is : -> "<<letter[plaintext[i]]<<endl;
    }
    cout<<"\nFinally encrypted output is: "<<encrypt<<endl;

    //for decrypted
    string decrypt="";
    for(int i=0;encrypt[i];i++)
    {
        cout<<encrypt[i]<<" decrypted is : -> "<<dec[encrypt[i]]<<endl;
        decrypt+=dec[encrypt[i]];
    }
    cout<<"Finally decrypted is :-> "<<decrypt<<endl;


return 0;}


