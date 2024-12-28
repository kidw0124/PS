#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using ll = long long;
using LL = __int128;
using pll = pair<ll, ll>;
using ld = long double;

constexpr int mod = 1'000'000'007;
constexpr ll inv2 = 500'000'004;
constexpr ll inv3 = 333'333'336;
constexpr ll inv3_2 = 666'666'672;

ll modpow(ll a, ll b, ll MOD=mod){
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ret;
}
ll modinv(ll a, ll MOD=mod){
    return modpow(a,MOD-2,MOD);
}
int inverse(int x, int mod) {
    return x == 1 ? 1 : mod - mod / x * (ll)inverse(mod % x, mod) % mod;
}
// operator pll +
pll operator+(const pll& a, const pll& b) {
    return {(a.first + b.first) % mod, (a.second + b.second) % mod};
}
pll operator%(const pll& a, const ll& b) {
    return {a.first % b, a.second % b};
}
pll operator*(const pll& a, const pll& b) {
    return pll({a.first*b.second+a.second*b.first-a.first*b.first,
                -a.first*b.first+a.second*b.second})%mod;
}
pll modpow(pll a, ll b) {
    pll ret={0,1};
    while(b){
        if(b&1)ret=ret*a;
        a=a*a;
        b>>=1;
    }
    return ret;
}
ll k;
void xorself(vector<pll>& a) {
    int m = (int) a.size();
    for (int n = m / 3; n; n/=3){
        for (int i = 0; i < m; i += n*3){
            for (int j = 0; j < n; j++) {
                pll x = a[i + j], y = a[i + j + n], z=a[i + j + n + n];
                a[i + j] = (x + y + z) % mod;
                a[i + j + n] = (x + y * pll(1,0) + z * pll(-1, -1)) % mod;
                a[i + j + n + n] = (x + y * pll(-1, -1) + z * pll(1,0)) % mod;
            }
        }
    }
    for (int i = 0; i < m; i++) {
//        c[i] = (ll) a[i] * a[i] % mod;
        a[i]=modpow(a[i],k);
    }
    pll inv_m = {0,inverse(m, mod)};

    for (int n = 1; n < m; n *= 3){
        for (int i = 0; i < m; i += n*3){
            for (int j = 0; j < n; j++) {
                pll x = a[i + j], y = a[i + j + n], z=a[i + j + n + n];
                a[i + j] = (x + y + z) % mod;
                a[i + j + n] = (x + y * pll(-1, -1) + z * pll(1,0)) % mod;
                a[i + j + n + n] = (x + y * pll(1, 0) + z * pll(-1,-1)) % mod;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        a[i] = a[i] * inv_m;
    }
}

void solve() {
    ll i,j;
    ll n,m;
    cin>>n>>m>>k;
    ll n3= modpow(3,n);
    vector<pll>a(n3);
    for(i=0;i<m;i++){
        int cnt;
        cin>>cnt;
        ll tmp=0;
        for(j=0;j<cnt;j++){
            int x;char c;
            cin>>x>>c;
            x--;
            if(c=='L'){
                tmp+=modpow(3,n-1-x);
            }
            else{
                tmp+=2*modpow(3,n-1-x);
            }
        }
        a[tmp].second++;
    }
    xorself(a);
    if(a[0].second<0)a[0].second+=mod;
    cout<<a[0].second<<'\n';
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
//    preprocess();
    ll t=1;
//    cin>>t;
    while(t--)solve();
#ifdef kidw0124
    cout<<clock()-beg<<"ms\n";
#endif
}
