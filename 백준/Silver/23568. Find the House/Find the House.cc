#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n;
    cin>>n;
    ll ans=0;
    for(i=0;i<n;i++){
        ll a,c;
        char b;
        cin>>a>>b>>c;
        if(b=='L')ans-=c;
        else ans+=c;
    }
    cin>>n;
    ans+=n;
    cout<<ans;
}
