#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<(a*b<c*d?"Eurecom":a*b>c*d?"TelecomParisTech":"Tie")<<'\n';
    }
}