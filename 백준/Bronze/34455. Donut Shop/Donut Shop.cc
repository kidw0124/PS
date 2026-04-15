#include<bits/stdc++.h>
using ll=long long;
using namespace std;
int main(){
    ll a,n;
    char c;
    cin>>a>>n;
    while(cin>>c){
        cin>>n;
        if(c=='+')a+=n;
        else a-=n;
        }
    cout<<a;}