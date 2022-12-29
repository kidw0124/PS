#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i;
    cin>>n;
        string str;
    getline(cin,str);
    for(i=1;i<=n;i++){
        getline(cin,str);
        cout<<i<<". "<<str<<'\n';
    }
}