#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using ll = long long;
using LL = __int128;
using pll = pair<ll, ll>;

ll modpow(ll a, ll b, ll mod=1e9+7){
    ll res = 1;
    while(b){
        if(b&1) res = res*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod=1e9+7){
    return modpow(a, mod-2, mod);
}

void preprocess() {
    ;
}

void solve() {
    ll i,j;
    ll n,m;
    cin>>n>>m;
    ll ans = 0;
    for(i=1;i<=n;i++){
        ans+=modinv(modpow(i,m));
        ans%=(ll)1e9+7;
        cout<<ans<<' ';
    }
    cout<<'\n';
}

int main() {
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    clock_t beg = clock();
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    preprocess();
    ll t=1;
//    cin>>t;
    while(t--)solve();
#ifdef kidw0124
    cout<<clock()-beg<<"ms\n";
#endif
}
