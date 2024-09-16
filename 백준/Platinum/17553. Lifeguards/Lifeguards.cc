#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma gcc optimize("O3,unroll-loops")
#pragma gcc target("avx,avx2,fma")
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pll = pair<ll,ll>;

constexpr ll MOD = 1e9+7;
constexpr ll MOD_2=500'000'004;
constexpr ll MOD_4=250'000'002;
constexpr ll MOD_8=125'000'001;

void preprocess(){

}

void solve() {
    ll i,j,k;
    ll n;
    ll INF=1e17;
    cin>>n;
    vector<pll>arr(n);
    map<ll,vector<ll>>mp;
    for(i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
        mp[arr[i].first].push_back(arr[i].second);
    }
    for(auto& [x,y]:mp){
        sort(y.begin(),y.end());
    }
    sort(arr.begin(),arr.end());
    ll cnt=0;
    auto [nowx,nowy]=arr[n/2];
    cout<<nowx-INF<<' '<<nowy-1<<'\n';
    if(n&1){
        cout<<nowx+INF<<' '<<nowy+1<<'\n';
    }
    else{
        cout<<nowx+INF<<' '<<nowy<<'\n';
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
