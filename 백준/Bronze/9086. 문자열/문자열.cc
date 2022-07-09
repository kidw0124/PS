#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        cout<<str[0]<<str[str.size()-1]<<'\n';
    }
}