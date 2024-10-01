#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = long long;

ll ans=0;

constexpr ll bitsize=30;

void solve() {
    ll i,j;
    ll n,q;
    cin>>n>>q;
    vector<ll>arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=0;i<q;i++){
        ll t;
        cin>>t;
        if(t==1){
            ll x,y;
            cin>>x>>y;
            ll sum=0;
            for(j=x-1;j<y;j++){
                sum+=arr[j];
            }
            cout<<sum<<'\n';
            swap(arr[x-1],arr[y-1]);
        }
        else{
            ll x,y;
            cin>>x>>y;
            ll sum=0;
            for(j=x-1;j<y;j++){
                sum+=arr[j];
            }
            cin>>x>>y;
            for(j=x-1;j<y;j++){
                sum-=arr[j];
            }
            cout<<sum<<'\n';
        }
    }

}

int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}