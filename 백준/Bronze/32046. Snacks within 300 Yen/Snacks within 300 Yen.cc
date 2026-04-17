#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll i,j;
    ll n;
    cin>>n;
    if(!n)exit(0);
    vector<ll>arr(n);
    ll ans=0;
    for(i=0;i<n;i++){
        cin>>arr[i];
        if(ans+arr[i]<=300)ans+=arr[i];
    }
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    while(true)solve();
}