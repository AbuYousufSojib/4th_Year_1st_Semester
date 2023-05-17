#include<bits/stdc++.h>
using namespace std;
int main() {
    cout<<"Enter the message:\n";
    string s, t="",ss;
    getline(cin, s);
    int l, choice;
    l = s.size();
    cout<<"Enter your choice \n1. Encryption \n2. Decryption \n";
    cin>>choice;
    ss=s;
    if(choice==1){
        //for(int key=1;key<=26;key++){
        int key = 3;
            for(int i=0;i<s.size();i++){
                if(s[i]>='a' && s[i]<='z'){
                    if(s[i]>'z'){
                        s[i] = s[i]+'z'+'a'-1;
                    }
                    t+=(s[i]-'a'+key)%26+'a';
                }
                else if(s[i]>='A' && s[i]<='Z'){
                    if(s[i]>'Z'){
                        s[i] = s[i]+'Z'+'A'-1;
                    }
                    t+=(s[i]-'A'+key)%26+'A';
                }
                //t+=(s[i]-'A'+key)%26+'A';
            }
            cout<<"\nEncrypted message is "<<t<<'\n';
            s = ss;
            t = "";
        }
    //}
    else if(choice==2){
        //for(int key=1;key<=26;key++){
        int key = 3;
            for(int i=0;i<s.size();i++){
                if(s[i]>='a' && s[i]<='z'){
                    if(s[i]<'a'){
                        s[i] = s[i]+'z'+'a'-1;
                    }
                    t+=(s[i]-'a'-key+26)%26+'a';
                }
                else if(s[i]>='A' && s[i]<='Z'){
                    if(s[i]<'A'){
                        s[i] = s[i]+'Z'+'A'-1;
                    }
                    t+=(s[i]-'A'-key+26)%26+'A';
                }
                //t+=(s[i]-'A'+key)%26+'A';
            }
            cout<<"\nDecrypted message is "<<t<<'\n';
            s = ss;
            t = "";
        }
    //}

}
