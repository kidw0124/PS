#include<bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 119 << 23 | 1;

int mul(int a, int b) {
    return 1LL * a * b % mod;
}

ll powm(ll x, ll n) {
    int ret = 1;
    for (; n>0; n >>= 1) {
        if (n & 1) ret = mul(ret, x);
        x = mul(x, x);
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector v(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i],v[i]<<=1,v[i]|=1;
//    sort(v.begin(), v.end());

    int rank = 0;
    for (int bit = 0; bit < 31; bit++) {
        int i;
        for ( i = rank; i < n; i++){
            if (v[i] >> bit & 1) {
                swap(v[rank], v[i]);
                break;
            }
        }
        if (i==n) continue;
        for (int i = rank + 1; i < n; i++) {
            if (v[i] >> bit & 1)v[i] ^= v[rank];
        }
        rank++;
    }
    ll ans=rank*(ll)(rank-1)/2+(n-rank)*(ll)(rank-1);
    cout<<powm(2,ans)<<'\n';
}