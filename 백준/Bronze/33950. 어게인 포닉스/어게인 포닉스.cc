#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    while(n--){
        string str;
        cin>>str;
        str+='\n';
        for(int i=0;i<str.size();i++){
            if(str[i]=='P')if(str[i+1]=='O')cout<<str[i]<<'H';
            else cout<<str[i];else cout<<str[i];
            }}
}