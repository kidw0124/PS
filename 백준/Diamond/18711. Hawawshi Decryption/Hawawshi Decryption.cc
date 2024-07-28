#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using ld = long double;

int modadd(int a, int b, const int p) {
    return a + b < p ? a + b : a + b - p;
}

int modmul(int a, int b, const int p) {
    return 1LL * a * b % p;
}

int modpow(int x, int n, const int p) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = modmul(ret, x, p);
        x = modmul(x, x, p);
    }
    return ret;
}

const int B = 10000;
int prv_a = -1, prv_n = -1, prv_p = -1, m;
unordered_set<int> buc;

void init(int a, int n, const int p) {
    m = (n - 1) / B;
    for (int i = 0; i < m; i++) {
        int r1 = modpow(a, i * B, p);
        int r2 = modpow(r1, p - 2, p);
        buc.insert(r2);
    }
}

bool check(int a, int b, int n, const int p) { // a^0, ..., a^{n - 1} 중 b가 있는지 여부 (mod p)
    if (a != prv_a || n != prv_n || p != prv_p) {
        prv_a = a;
        prv_n = n;
        prv_p = p;
        buc.clear();
        init(a, n, p);
    }
    for (int i = m * B; i < n; i++) {
        int val = modpow(a, i, p);
        if (val == b) return 1;
    }
    int x = modpow(b, p - 2, p);
    for (int i = 0; i < B; i++) {
        if (buc.count(x)) return 1;
        x = modmul(x, a, p);
    }
    return 0;
}

void solve() {
    int n, x, A, B, a, b, p; cin >> n >> x >> A >> B >> a >> b >> p;
    if(a==1){
        int cnt=0,tot=0;
        int binv=modpow(b,p-2,p);
        for(int i=A;i<=B;i++){
            int t=((x-i)%p+p)%p;
            t=modmul(t,binv,p);
            tot++;
            if(t>=0&&t<n)cnt++;
        }
        ll g=gcd(cnt,tot);
        cout<<cnt/g<<"/"<<tot/g<<'\n';
        return;
    }
    int bb=b*(ll)modpow(a-1,p-2,p)%p;
    x=(x+bb)%p;
    int cnt=0,tot=0;
    for(int i=A;i<=B;i++){
        int c=(i+bb)%p;
        c=modpow(c,p-2,p);
        tot++;
        if(c==0&&x==0){
            cnt++;
            continue;
        }
        else if(x==0){
            continue;
        }
        else if (check(a,(x*(ll)c)%p,n,p))cnt++;
    }
    ll g=gcd(cnt,tot);
    cout<<cnt/g<<"/"<<tot/g<<'\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}