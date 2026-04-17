#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    s+='.';
    for(int i=0;i<n;i++){
        if(s[i]=='\\'){
               i+=3;
            if(s[i+1]=='.')cout<<'v';
            else cout<<'w',i+=3;
           
        }
    }
}