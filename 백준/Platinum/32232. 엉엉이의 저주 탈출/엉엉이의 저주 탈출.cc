#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using LL = __int128;
using pll = pair<ll, ll>;
using ld = long double;

int modpow(int x, int n, int mod) {
    int res = 1;
    for (; n; n >>= 1) {
        if (n & 1) res = (ll)res * x % mod;
        x = (ll)x * x % mod;
    }
    return res;
}
int modinv(int x, int y) {
    int m = y;
    int a = 1, b = 0;
    while (x) {
        b -= y / x * a;
        y %= x;
        swap(a, b);
        swap(x, y);
    }
    return (b % m + m) % m;
}

constexpr int MOD = 1'000'000'007;
constexpr int MOD_2 = (MOD + 1) / 2;

void solve() {
    int n, m;
    cin >> n >> m;
    if(m&1){
        if(n==1){
            m-=2;
            ll tmp=modinv(m,MOD);
            cout<<(tmp*tmp%MOD *(m>>1)%MOD *((m+1)>>1)<<1)%MOD<<'\n';
        }
        else{
            ll tmp=modinv(modpow(m-2,n,MOD),MOD);
            tmp+=1;
            cout<<tmp*MOD_2%MOD<<'\n';
        }
    }
    else{
        cout<<MOD_2<<'\n';
    }
}

int main() {
    int t;
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
}
