#include<bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int INF=1e9+7;

void solve() {
    ll i,j;
    ll n;
    cin>>n;
    vector<ll>arr(n);
    ll r=0;
    for(auto &k:arr)cin>>k,r+=abs(k),k=k*2-abs(k);
    ll ans=max(0ll,arr[0]);
    ll sx=arr[0];
    for(i=1;i<n;i++){
        if(sx<0)sx=arr[i];
        else sx+=arr[i];
        ans=max(ans,sx);
    }
    cout<<r+ans;

}

int main() {
#ifdef kidw0124
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    solve();
}