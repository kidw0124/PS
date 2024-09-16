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
    ll n,m,sum=0;
    cin>>n>>m;
    vector<ll>arr(n);
    priority_queue<ll>pq;
    for(i=0;i<n;i++){
        cin>>arr[i];
        if((i+1)%(m+1)==0){
            pq.push(-arr[i]);
        }
        else{
            if(pq.size()&&-pq.top()<arr[i]){
                sum-=pq.top();
                pq.pop();
                pq.push(-arr[i]);
            }
            else{
                sum+=arr[i];
            }
        }
    }
    cout<<sum;




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
