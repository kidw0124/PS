#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using ll = long long;
using LL = __int128;
using pll = pair<ll, ll>;

constexpr int MAX = 50'000'000;
constexpr int MOD = 1'000'000'007;

vector<int> phi(MAX);

vector <int> prime(3444396);
int cnt=0;
bitset<MAX> is_composite;
ll n;
vector<int> ans(10005, -1);

void sieve (int n) {
    is_composite.set();
    phi[1] = 1;
    int z;
    for (int i = 2; i < n; ++i) {
        if (is_composite[i]) {
            prime[cnt++]=i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < cnt && i * (ll)prime[j] < n; ++j) {
            z=i * prime[j];
            is_composite.reset(z);
            if (i % prime[j] == 0) {
                phi[z] = phi[i] * prime[j];
                break;
            } else {
                phi[z] = phi[i] * phi[prime[j]];
            }
        }
    }
    for(int i=2;i<n;i++)phi[i]=((ll)i*phi[i]+phi[i-1])%MOD;
}

//ll S(ll x) {
//    ll i, j,z;
//    if (x < MAX) return phi[x];
//    if (mp.find(x) != mp.end()) return mp[x];
//    ll xmod=x%MOD;
//    ll ret = xmod*(xmod+1)%MOD*(xmod<<1|1)%MOD*333333336%MOD;
//    for (i = 2; i <= x; i = j+1) {
//        z=x/i;
//        j = x / z;
//        ret -= ((j+i)%MOD*((j-i+1)%MOD))%MOD * S(z) %MOD;
//    }
//    ret%=MOD;
//    if(ret<0)ret+=MOD;
//    ret=(ret*500000004)%MOD;
//    return mp[x] = ret;
//}


int S(ll x) {
    ll i, j;
    if (x < MAX) return phi[x];
    ll nx=n/x;
    if (ans[nx] != -1) return ans[nx];
    ll xmod=x%MOD;
    ll ret = xmod*(xmod+1)%MOD*(xmod<<1|1)%MOD*333333336%MOD;
    for (i = 2; i <= x; i = j+1) {
        j = x / (x/i);
        ret -= ((j+i)%MOD*((j-i+1)%MOD))%MOD * S(x/i) %MOD;
    }
    ret%=MOD;
    if(ret<0)ret+=MOD;
    ret=(ret*500000004)%MOD;
    return ans[nx] = ret;
}

void preprocess() {
    ;
}

void solve() {
    ll i,j;
    cin>>n;
    sieve(min((ll)MAX, n+1));
    cout<<((ll)S(n)*3+1000000006)%MOD<<'\n';
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
