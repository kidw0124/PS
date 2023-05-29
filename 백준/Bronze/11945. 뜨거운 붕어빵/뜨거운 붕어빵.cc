#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,i;
    string str;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>str;
        reverse(str.begin(),str.end());
        cout<<str<<'\n';
    }
}