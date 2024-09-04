#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        str.erase(unique(str.begin(),str.end()),str.end());
        cout<<str<<'\n';
    }
}