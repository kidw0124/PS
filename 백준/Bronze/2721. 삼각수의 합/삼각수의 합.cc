#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,ans=0;
        cin>>n;
        while(n){
            ans+=n*(n+2)*(n+1)/2;
            n--;
        }
        cout<<ans<<'\n';
    }
}