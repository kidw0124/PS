#include<bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll mod=1e9+7;

void solve(){
    ll i,j;
    ll n,m;
    cin>>n>>m;
    vector<ll> arr(n),dif(n),sum(n),dif2(n),sum2(n);
    for(i=0;i<n;i++){
        cin>>arr[i];
        if(i)dif[i]=max(0ll,arr[i]-arr[i-1]);
        if(i)dif2[i]=max(0ll,arr[i-1]-arr[i]);
    }
    for(i=1;i<n;i++)sum[i]=sum[i-1]+dif[i],sum2[i]=sum2[i-1]+dif2[i];
    ll ans=0;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(sum[j]-sum[i]<=m)ans=max(ans,j-i+1);
            if(sum2[j]-sum2[i]<=m)ans=max(ans,j-i+1);
        }
    }
    cout<<ans<<'\n';
}

int main(){
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    ll t=1;
//    cin>>t;
    while(t--)solve();
}
