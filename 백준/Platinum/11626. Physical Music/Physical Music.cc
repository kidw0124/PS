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
    cin>>n;
    set<ll>st;
    for(i=1;i<=n;i++){
        st.insert(i);
    }
    vector<ll>arr(n);
    vector<ll>ans;
    for(i=0;i<n;i++){
        cin>>arr[i];
        if(*st.begin()!=arr[i]){
            ans.push_back(arr[i]);
        }
        st.erase(arr[i]);
    }
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<"\n";
    for(auto& x:ans){
        cout<<x<<" ";
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
    cin >> tc;
    while (tc--) solve();
}
