#include<bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll mod=1e9+7;

void solve(){
    ll i,j;
    ll n,m;
    cin>>n>>m;
    vector<ll>arr(n+1);
    arr[0]=0;
    for(i=1;i<=n;i++){
        cin>>arr[i];
        arr[i]=min(m,arr[i]);
    }
    arr.push_back(m);
    sort(arr.begin(),arr.end());
    ll ans=0;
    for(i=0;i<=n;i++){
        ans=max(ans,arr[i+1]-arr[i]);
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
