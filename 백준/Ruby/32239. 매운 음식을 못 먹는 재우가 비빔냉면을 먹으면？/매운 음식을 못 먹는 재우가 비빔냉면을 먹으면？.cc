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
vector<ll> m2,re_m,inv_m,inv_re_m;
ll k;

void xormul(vector<int> a, vector<int> b, vector<int> &c) {
    int m = (int) a.size();
    c.resize(m);
    int cnt=m2.size()-1;
    for (int n = m / 2; n > 0; n >>= 1) {
        for (int i = 0; i < m; i += n << 1) {
            for (int j = 0; j < n; j++) {
                int x = a[i + j], y = a[i + j + n], z = b[i + j], w = b[i + j + n];
                a[i + j] = (x + y) % mod;
                a[i + j + n] = (x - y * re_m[cnt]) % mod;
                b[i + j] = (z + w) % mod;
                b[i + j + n] = (z - w * re_m[cnt]) % mod;
            }
        }
        cnt--;
    }
    cnt=0;
    for (int i = 0; i < m; i++) {
        c[i] = (ll) a[i] * b[i] % mod;
        c[i]=modpow(c[i],k);
    }
    for (int n = 1; n < m; n <<= 1){
        for (int i = 0; i < m; i += n<<1){
            for (int j = 0; j < n; j++) {
                int x = c[i + j], y = c[i + j + n];
                c[i + j] = (y+(x - y)* inv_re_m[cnt]) % mod;
                c[i + j + n] = (x - y+(y-x) * inv_re_m[cnt]) % mod;
            }
        }
        cnt++;
    }
//    for(int i=0;i<m;i++)c[i]=c[i]*inv_m[i]%mod;
}
void xorself(vector<int>& a) {
    int m = (int) a.size();
    int cnt=m2.size()-1;
    for (int n = m / 2; n; n >>= 1){
        for (int i = 0; i < m; i += n<<1){
            for (int j = 0; j < n; j++) {
                int x = a[i + j], y = a[i + j + n];
                a[i + j] = (x + y) % mod;
                a[i + j + n] = (x-y*re_m[cnt])  % mod;
            }
        }
        cnt--;
    }
    for (int i = 0; i < m; i++) {
//        c[i] = (ll) a[i] * a[i] % mod;
        a[i]=modpow(a[i],k);
    }
    cnt=0;
    for (int n = 1; n < m; n <<= 1){
        for (int i = 0; i < m; i += n<<1){
            for (int j = 0; j < n; j++) {
                int x = a[i + j], y = a[i + j + n];
                a[i + j] = (y+(x - y)* inv_re_m[cnt]) % mod;
                a[i + j + n] = (x - y+(y-x) * inv_re_m[cnt]) % mod;
            }
        }
        cnt++;
    }

//    for(int i=0;i<m;i++)c[i]=c[i]*inv_m[i]%mod;
}
//void fwht_xor_k(vector<int>&a, int k){
//    if(k==1)return;
//    else{
//        auto b=a;
//        vector<int> c;
//        fwht_xor_k(b,k>>1);
//        xorself(b,c);
//        if(k&1){
//            xormul(a,c,b);
//            swap(a,b);
//        }
//        else swap(a,c);
//    }
//}

//void fwht_xor_k_ver2(vector<int>&a, int k){
//    int n=(int)a.size();
//    vector<int> b(n);
//    b[0]=1;
//    vector<int> c;
//    auto xormul=[](vector<int> a, vector<int> b, vector<int> &c) {
//        int m = (int) a.size();
//        c.resize(m);
//        for (int n = m / 2; n > 0; n >>= 1)
//            for (int i = 0; i < m; i += n<<1)
//                for (int j = 0; j < n; j++) {
//                    int x = a[i + j], y = a[i + j + n];
//                    a[i + j] = (x + y) % mod;
//                    a[i + j + n] = (x-y*inv2)  % mod;
//                }
//        for (int n = m / 2; n > 0; n >>= 1)
//            for (int i = 0; i < m; i += n<<1)
//                for (int j = 0; j < n; j++) {
//                    int x = b[i + j], y = b[i + j + n];
//                    b[i + j] = (x+y)  % mod;
//                    b[i + j + n] = (x-y*inv2) % mod;
//                }
//        for (int i = 0; i < m; i++)
//            c[i] = (ll)a[i] * b[i] % mod;
//        for (int n = 1; n < m; n <<= 1)
//            for (int i = 0; i < m; i += n<<1)
//                for (int j = 0; j < n; j++) {
//                    int x = c[i + j], y = c[i + j + n];
//                    c[i + j] = (x + y + (ll)y)  * inv3 % mod;
//                    c[i + j + n] = (x - y) * inv3_2 % mod;
//                }
//        for(int i=0;i<m;i++)c[i]=(c[i]+mod)%mod;
//    };
//    while(k){
//        if(k&1){
//            xormul(a,b,c);
//            swap(b,c);
//        }
//        xormul(a,a,c);
//        swap(a,c);
//        k>>=1;
//    }
//    swap(a,b);
//}

void solve() {
    ll i,j;
    ll n;
    cin>>n;
    vector<int>a(1<<n);
    m2.resize(n),re_m.resize(n)
            ,inv_m.resize(n),inv_re_m.resize(n);
    for(i=0;i<n;i++)cin>>m2[i];
    ll m;
    cin>>m;
    for(i=0;i<n;i++){
        inv_m[i]=modinv(modpow(m2[i],n));
        inv_re_m[i]=modinv(m2[i]);
        re_m[i]=modinv(m2[i]-1);
    }
    for(i=0;i<m;i++){
        ll p,tmp=0;
        cin>>p;
        for(j=0;j<p;j++){
            ll x;
            cin>>x;
            x--;
            tmp|=(1<<x);
        }
        a[tmp]++;
    }
    ll invm=modinv(m);
    for(i=0;i<(1<<n);i++) {
        a[i]=(ll)a[i]*invm%mod;
    }
    cin>>k;
    xorself(a);
//    fwht_xor_k(a,k);
    if(a[0]<0)a[0]+=mod;
    cout<<a[0]<<'\n';

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
