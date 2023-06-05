#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
typedef vector<ll> poly;

const ll w = 3;
const ll mod = 998244353;

ll pw(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ret;
}

void ntt(poly& f, bool inv = 0) {
    int n = f.size(), j = 0;
    vector<ll> root(n >> 1);
    for (int i = 1; i < n; i++) {
        int bit = (n >> 1);
        while (j >= bit) {
            j -= bit;
            bit >>= 1;
        }
        j += bit;
        if (i < j) swap(f[i], f[j]);
    }
    ll ang = pw(w, (mod - 1) / n);
    if (inv) ang = pw(ang, mod - 2);
    root[0] = 1;
    for (int i = 1; i < (n >> 1); i++) root[i] = root[i - 1] * ang % mod;
    for (int i = 2; i <= n; i <<= 1) {
        int step = n / i;
        for (int j = 0; j < n; j += i) {
            for (int k = 0; k < (i >> 1); k++) {
                ll u = f[j | k], v = f[j | k | i >> 1] * root[step * k] % mod;
                f[j | k] = (u + v) % mod;
                f[j | k | i >> 1] = (u - v) % mod;
                if (f[j | k | i >> 1] < 0) f[j | k | i >> 1] += mod;
            }
        }
    }
    ll t = pw(n, mod - 2);
    if (inv)
        for (int i = 0; i < n; i++) f[i] = f[i] * t % mod;
}

vector<ll> multiply(poly& _a, poly& _b) {
    vector<ll> a(all(_a)), b(all(_b));
    int n = 2;
    while (n < a.size() + b.size()) n <<= 1;
    a.resize(n);
    b.resize(n);
    ntt(a);
    ntt(b);
    for (int i = 0; i < n; i++) a[i] = a[i] * b[i] % mod;
    ntt(a, 1);
    return a;
}
vector<ll>& operator+=(vector<ll>& a, const vector<ll>& b) {
    a.resize(max(a.size(), b.size()));
    for (int i = 0; i < b.size(); i++) a[i] += b[i];
    for (int i = 0; i < b.size(); i++) a[i] %= mod;
    return a;
}
vector<ll>& operator-=(vector<ll>& a, const vector<ll>& b) {
    a.resize(max(a.size(), b.size()));
    for (int i = 0; i < b.size(); i++) a[i] += mod - b[i];
    for (int i = 0; i < b.size(); i++) a[i] %= mod;
    return a;
}

using charac = vector<ll>;

struct matrix {
    charac a, b, c, d;
    matrix operator*(matrix& r) {
        matrix tmp;
        tmp.a += multiply(a, r.a);
        tmp.a += multiply(b, r.c);
        tmp.b += multiply(a, r.b);
        tmp.b += multiply(b, r.d);
        tmp.c += multiply(c, r.a);
        tmp.c += multiply(d, r.c);
        tmp.d += multiply(c, r.b);
        tmp.d += multiply(d, r.d);
        return tmp;
    }
    matrix operator^(ll r) {
        if (r == 0) {
            return {{1}, {0}, {0}, {1}};
        } else if (r == 1) {
            return *this;
        } else {
            matrix tmp = (*this) ^ (r >> 1);
            if (r & 1) {
                return tmp * tmp * (*this);
            } else {
                return tmp * tmp;
            }
        }
    }
};
vector<ll> mat;
vector<matrix> precom(15);
charac f(ll x, ll n);

void get_charac(charac& res, int st, int en) {
    int n = en - st + 1;
    ll mid = (n >> 1) + st;
    if (n == 1) {
        res = {mat[st + 0], mod - 1};
    } else if (n == 2) {
        res = {mat[st + 0] * mat[st + 1] - 1, -mat[st + 0] - mat[st + 1], 1};
    } else if (n == 3) {
        res = {mat[st + 0] * mat[st + 1] * mat[st + 2] - mat[st + 0] * mat[st + 1] - mat[st + 0] * mat[st + 2] - mat[st + 1] * mat[st + 2] + 1, -mat[st + 0] * mat[st + 1] - mat[st + 0] * mat[st + 2] - mat[st + 1] * mat[st + 2] + mat[st + 0] + mat[st + 1] + mat[st + 2], mat[st + 0] + mat[st + 1] + mat[st + 2], mod - 1};
    } else {
        charac tmp = {n - 2, mod - 1};
        charac fn = f(n - 2, n);
        tmp = multiply(tmp, tmp);
        charac ret = multiply(tmp, fn);
        tmp = {2 * n - 4, mod - 2};
        fn = f(n - 3, n);
        ret -= multiply(tmp, fn);
        fn = f(n - 4, n);
        ret += fn;
        res = ret;
    }
}

void dopre(ll n) {
    precom[0] = {{n - 3, mod - 1}, {mod - 1}, {1}, {0}};
    for (int i = 1; i < 15; i++) {
        precom[i] = precom[i - 1] * precom[i - 1];
    }
}

charac f(ll x, ll n) {
    matrix s = {{1}, {0}, {0}, {1}};
    if (x == 0) {
        return {1};
    }
    x--;
    ll now = 0;
    while (x) {
        if (x & 1) {
            s = s * precom[now];
        }
        x >>= 1;
        now++;
    }
    vector<ll> a({n - 3, mod - 1});
    charac ret = multiply(s.a, a);
    ret += s.b;
    return ret;
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    if (argc > 2 && strcmp(argv[1], "-o") == 0) {
        freopen((string(argv[2]) + ".out").c_str(), "w", stdout);
        freopen((string(argv[2]) + ".in").c_str(), "r", stdin);
    }
    ll n, d, i, j;
    cin >> n >> d;
    dopre(n);
    mat.resize(n);
    for (i = 1; i < n - 1; i++) {
        mat[i] = n - 3;
    }
    mat[0] = mat[n - 1] = n - 2;
    charac cans(n + 1);
    get_charac(cans, 0, n - 1);
    vector<ll> character = cans;
    reverse(character.begin(), character.begin() + n + 1);
    character.resize(d);
    if (character[0] > 0 && n % 2 == 0)
        for (ll& x : character) x = -x;
    vector<ll> sum(d, 0);
    sum[0] = 1;
    if (d > 1) sum[1] = character[1];
    for (i = 2; i <= min(d - 1, n); i++) {
        for (j = 1; j <= i - 1; j++) {
            sum[i] += (character[j] * sum[i - j]) % mod;
            sum[i] %= mod;
        }
        sum[i] += (character[i] * i) % mod;
        sum[i] %= mod;
    }
    for (; i < d; i++) {
        for (j = 1; j <= n; j++) {
            sum[i] += (character[j] * sum[i - j]) % mod;
            sum[i] %= mod;
        }
    }
    ll ans = (sum[d - 1] + mod) % mod;
    for (i = 0; i < d - 2; i++) {
        ans *= n;
        ans %= mod;
    }
    cout << ans << '\n';
}