#include <bits/stdc++.h>
using namespace std;
//for string process with repeated element
string stringprocessing (string s)
{
    char ch=' ';
    string str=""; // output string
    int len=1;
    for(int i=0;i<s.size();i++)
    {
      if(ch==s[i])
      {
        if(len%2==0)
        {
           str+='x';             //same hole maje x tarpor 2nd element push korci
           str+=s[i];
           len+=2;ch=s[i];
        }
        else
        {
           str+=s[i];
           ch=s[i];len++;
        }
      }
      else
      {
         str+=s[i];ch=s[i];len++;
      }
    }

    if(str.size()%2!=0)str+='x';
    return str;
}

vector<vector<char> > keyfrommatrix(string key)
{
     bool ok=0; // i or j any letter existness check
     vector<char>v;
     vector<vector<char> >matrix; //for create 2D matrix
     for(int i=0;i<key.size();i++)
    {
      if(find(v.begin(), v.end(),key[i])==v.end()){
        if((key[i]=='i' or key[i]=='j'))
        {
            if(ok==0){
           v.push_back('j');ok=1;}
           else continue;
        }
        else
        v.push_back(key[i]);
        }
    }
    for(int i=0;i<26;i++)
    {
      char c='a'+i;
      if(find(v.begin(), v.end(),c)==v.end()){
        if(c=='i' or c=='j')
        {
           if(ok==0){
           v.push_back('j');ok=1;}
           else continue;
        }
        else
        v.push_back(c);}
      else continue;
    }
    for(int i=0;i<v.size();i+=5)
    {
       vector<char>temp;
       for(int j=i;j<i+5;j++)
       {
        if(v[j]=='j')v[j]='i';
        temp.push_back(v[j]);
       }
       matrix.push_back(temp);
    }
    return matrix;
}
//for position find pair letter
pair<int ,int> position (char c,vector<vector<char> >&matrix)
{
     pair<int ,int>pr;
     for(int i=0;i<5;i++)
    {
      for(int j=0;j<5;j++)
      {
        if(matrix[i][j]==c)
        {
            pr=make_pair(i,j);break;
        }
      }
    }
return pr;
}
int main()
{
    string s,key;
    cout<<"Enter string and key: "<<endl;
    cin>>s>>key;
    string st = stringprocessing(s); //get process string
    cout<<"Plain-Text is :"<<st<<endl;
    vector<vector<char> >matrix=keyfrommatrix(key); //get matrix

    cout<<"Key matrix is : \n";
    for(int i=0;i<5;i++)
    {
      for(int j=0;j<5;j++)
      {
        cout<<matrix[i][j]<<" ";
      }
      cout<<endl;
    }
    string encrypt="";
    for(int i=0;i<st.size();i+=2)
    {
    pair<int,int>pr1=position(st[i],matrix);
    pair<int,int>pr2=position(st[i+1],matrix);

    if(pr1.first == pr2.first or pr1.second==pr2.second)
    {
        if(pr1.first == pr2.first)
        {
           encrypt+=matrix[pr1.first][(pr1.second+1)%5];
           encrypt+=matrix[pr2.first][(pr2.second+1)%5];
           cout<<st[i]<<st[i+1]<<"-->encrypted ---->";
           cout<<matrix[pr1.first][abs(pr1.second+1)%5]<<matrix[pr2.first][(pr2.second+1)%5]<<endl;
        }
        else
        {
           encrypt+=matrix[(pr1.first+1)%5][pr1.second];
           encrypt+=matrix[(pr2.first+1)%5][pr2.second];
           cout<<st[i]<<st[i+1]<<"-->encrypted ---->";
           cout<<matrix[(pr1.first+1)%5][pr1.second]<<matrix[(pr2.first+1)%5][pr2.second]<<endl;
        }
    }
    else
    {
        encrypt+=matrix[pr1.first][pr2.second];
        encrypt+=matrix[pr2.first][pr1.second];
        cout<<st[i]<<st[i+1]<<"-->encrypted ---->";
        cout<<matrix[pr1.first][pr2.second]<<matrix[pr2.first][pr1.second]<<endl;
    }
    }
    cout<<"Encrypted Text is : "<<encrypt<<endl;

    ////Decryption for ***********///////******
    string decrypt="";
    for(int i=0;i<encrypt.size();i+=2)
    {
    pair<int,int>pr1=position(encrypt[i],matrix);
    pair<int,int>pr2=position(encrypt[i+1],matrix);

    if(pr1.first == pr2.first or pr1.second==pr2.second)
    {
        if(pr1.first == pr2.first)
        {
           decrypt+=matrix[pr1.first][(5+pr1.second-1)%5]; //5 add because negative value circulary create
           decrypt+=matrix[pr2.first][(5+pr2.second-1)%5];
           cout<<encrypt[i]<<encrypt[i+1]<<"-->decrypted ---->";
           cout<<matrix[pr1.first][(5+pr1.second-1)%5]<<matrix[pr2.first][(5+pr2.second-1)%5]<<endl;
        }
        else
        {
           decrypt+=matrix[(5+pr1.first-1)%5][pr1.second];
           decrypt+=matrix[(5+pr2.first-1)%5][pr2.second];
           cout<<encrypt[i]<<encrypt[i+1]<<"-->decrypted ---->";
           cout<<matrix[(5+pr1.first-1)%5][pr1.second]<<matrix[(5+pr2.first-1)%5][pr2.second]<<endl;
        }
    }
    else
    {
        decrypt+=matrix[pr1.first][pr2.second];
        decrypt+=matrix[pr2.first][pr1.second];
        cout<<encrypt[i]<<encrypt[i+1]<<"-->decrypted ---->";
        cout<<matrix[pr1.first][pr2.second]<<matrix[pr2.first][pr1.second]<<endl;
    }
    }
    cout<<"Decrypted Text is : "<<decrypt<<endl;
    return 0;}
