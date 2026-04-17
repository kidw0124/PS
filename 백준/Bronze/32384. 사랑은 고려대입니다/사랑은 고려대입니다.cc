#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma gcc optimize("O3,unroll-loops")
#pragma gcc target("avx,avx2,fma")
using namespace std;
using namespace __gnu_pbds;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll MOD_2=5'000'000'004;
constexpr ll MOD_8=1'250'000'001;

void preprocess(){

}

void solve() {
    ll i,j,k;
    ll n,m;
    cin>>n;
    char arr[21]={
            'L','o','v','e','i','s','K','o','r','e','a','U','n','i','v','e','r','s','i','t','y'
    };
    while(n--){
        cout<<arr<<' ';
    }
    cout<<"\n";


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