#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using LL = __int128;
using pll = pair<ll, ll>;
using ld = long double;

ll modadd(ll a, ll b, ll mod) { return a + b < mod ? a + b : a + b - mod; }
ll modmul(ll a, ll b, ll mod) { return LL(a) * b % mod; }
ll modpow(ll x, ll n, ll mod) {
    ll res = 1;
    for (; n; n >>= 1) {
        if (n & 1) res = modmul(res, x, mod);
        x = modmul(x, x, mod);
    }
    return res;
}

bool is_prime(ll n) {
    if (n < 2 || n % 2 == 0 || n % 3 == 0) return n == 2 || n == 3;
    ll k = __builtin_ctzll(n - 1), d = n - 1 >> k;
    for (ll a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        ll p = modpow(a % n, d, n), i = k;
        while (p != 1 && p != n - 1 && a % n && i--) p = modmul(p, p, n);
        if (p != n - 1 && i != k) return 0;
    }
    return 1;
}

ll pollard(ll n) {
    auto f = [n](ll x) { return modadd(modmul(x, x, n), 3, n); };
    ll x = 0, y = 0, t = 30, p = 2, i = 1, q;
    while (t++ % 40 || gcd(p, n) == 1) {
        if (x == y) x = ++i, y = f(x);
        if (q = modmul(p, abs(x - y), n)) p = q;
        x = f(x), y = f(f(y));
    }
    return gcd(p, n);
}

vector<ll> factor(ll n) {
    if (n == 1) return {};
    if (is_prime(n)) return {n};
    ll x = pollard(n);
    auto l = factor(x), r = factor(n / x);
    l.insert(l.end(), r.begin(), r.end());
    sort(l.begin(), l.end());
    return l;
}

vector<pll> get_primes_and_cnt(ll n, const vector<ll>& arr) {
    vector<ll> f = factor(n);
    vector<int> cnt;
    for (int i = 0; i < f.size(); i++) {
        int j = i;
        while (j < f.size() && f[j] == f[i]) j++;
        cnt.push_back(j - i);
        i = j - 1;
    }
    f.erase(unique(f.begin(), f.end()), f.end());
    vector<pll> ret;
    for (int i = 0; i < f.size(); i++) {
        int j = 0;
        for (j = 0; j < arr.size(); j++) {
            if (arr[j] % f[i] == 0) break;
        }
        if (j == arr.size()) ret.push_back({f[i], cnt[i]});
    }
    return ret;
}

ll gcd(ll a, ll b) {
    a = abs(a), b = abs(b);
    return b ? gcd(b, a % b) : a;
}

ll v(ll p, ll x) {
    ll ret = 0;
    while (x % p == 0) {
        x /= p;
        ret++;
    }
    return ret;
}

ll lte_minus(ll p, ll goal, ll x, ll y) {
    ll vxmy = v(p, abs(x - y));
    if (p == 2) {
        if (vxmy >= goal) {
            return 0;
        } else {
            ll vxpy = v(p, abs(x + y));
            goal -= vxmy;
            goal -= vxpy;
            goal += 1;
            return max(1ll, goal);
        }
    } else {
        if (vxmy >= goal) {
            return 0;
        } else {
            goal -= vxmy;
            return goal;
        }
    }
}

ll lte_plus(ll p, ll goal, ll x, ll y, bool is_even) {
    ll vxpy = v(p, abs(x + y));
    if (p == 2) {
        if (is_even) {
            if (goal == 1) {
                return 1;
            } else {
                return -1;
            }
        } else {
            if (vxpy >= goal) {
                return 0;
            } else {
                if (goal == 1) {
                    return 1;  // 음 이거 dead code 인가?
                } else {
                    return -1;
                }
            }
        }
    } else {
        if (is_even)
            return -1;
        else {
            if (vxpy >= goal) {
                return 0;
            } else {
                goal -= vxpy;
                return goal;
            }
        }
    }
}

constexpr ll MOD = 1'000'000'007;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    ll g = arr[1] - arr[0];
    for (int i = 2; i < n; i++) g = gcd(g, arr[i] - arr[i - 1]);
    vector<pll> primes = get_primes_and_cnt(g, arr);
    ll ans = 1;
    bool is_even = false;
    for (int i = 0; i < primes.size(); i++) {
        ll p = primes[i].first;
        ll goal = primes[i].second * m;
        ll tmp = 0;
        for (int j = 1; j < n; j++) {
            if ((LL)arr[j] * arr[j - 1] >= 0) {
                ll x = abs(arr[j - 1]);
                ll y = abs(arr[j]);
                if (x > y) swap(x, y);
                ll res = lte_minus(p, goal, x, y);
                if (res == -1) {
                    cout << -1;
                    return 0;
                } else {
                    tmp = max(tmp, res);
                }
            }
        }
        if (p == 2 && tmp) {
            is_even = true;
        }
        for (int j = 1; j < n; j++) {
            if ((LL)arr[j] * arr[j - 1] < 0) {
                ll x = abs(arr[j - 1]);
                ll y = abs(arr[j]);
                if (x > y) swap(x, y);
                ll res = lte_plus(p, goal, x, y, is_even);
                if (res == -1) {
                    cout << -1;
                    return 0;
                } else {
                    tmp = max(tmp, res);
                }
            }
        }
        if (p == 2 && tmp) {
            is_even = true;
        }
        ans = modmul(ans, modpow(p, tmp, MOD), MOD);
    }
    cout << ans << '\n';
}
