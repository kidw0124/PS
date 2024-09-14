#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using LL = __int128;
using pll = pair<ll, ll>;

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

vector<ll> divisors(ll n) {
  vector<ll> f = factor(n);
  vector<int> cnt;
  for (int i = 0; i < f.size(); i++) {
    int j = i;
    while (j < f.size() && f[j] == f[i]) j++;
    cnt.push_back(j - i);
    i = j - 1;
  }
  f.erase(unique(f.begin(), f.end()), f.end());
  vector<ll> divs = {1};
  for (int i = 0; i < f.size(); i++) {
    int ds = divs.size();
    for (int j = 0; j < ds; j++) {
      ll mul = 1;
      for (int k = 0; k < cnt[i]; k++) {
        mul *= f[i];
        divs.push_back(divs[j] * mul);
      }
    }
  }
  return divs;
}

ll gcd(ll a, ll b) {
  a = abs(a), b = abs(b);
  return b ? gcd(b, a % b) : a;
}

void infty() {
  cout << "INFINITY\n";
  exit(0);
}

vector<pll> solve_equation(ll d) {
  // xy=d
  vector<ll> divs = divisors(abs(d));
  vector<pll> ret;
  for (ll div : divs) {
    ll x = div, y = d / div;
    ret.push_back({x, y});
    ret.push_back({-x, -y});
  }
  sort(ret.begin(), ret.end());
  ret.erase(unique(ret.begin(), ret.end()), ret.end());
  return ret;
}

vector<pll> solve(ll a, ll b, ll c, ll d) {
  //(ax+c)(ay+b)=d
  vector<pll> ret, candidates = solve_equation(d);
  for (auto [p, q] : candidates) {
    p -= c, q -= b;
    if (p % a == 0 && q % a == 0) {
      p /= a, q /= a;
      ret.push_back({p, q});
    }
  }
  sort(ret.begin(), ret.end());
  ret.erase(unique(ret.begin(), ret.end()), ret.end());
  return ret;
}

int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a == 0) {
    if (b == 0 && c == 0) {
      if (d == 0) {
        infty();
      } else {
        cout << 0 << '\n';
      }
    } else if (b == 0) {
      if (d % c) cout << 0 << '\n';
      else infty();
    } else if (c == 0) {
      if (d % b) cout << 0 << '\n';
      else infty();
    } else {
      ll g = gcd(b, c);
      if (d % g) {
        cout << 0 << '\n';
      } else {
        infty();
      }
    }
  } else {
    if (b == 0 && c == 0) {
      if (d % a) {
        cout << 0 << '\n';
      } else if (d == 0) {
        infty();
      } else {
        vector<pll> ans = solve(1, 0, 0, -d / a);
        cout << ans.size() << '\n';
        for (auto [x, y] : ans) {
          cout << x << ' ' << y << '\n';
        }
      }
    } else if (b == 0) {
      if (d == 0) {
        infty();
      } else {
        vector<pll> ans = solve(a, 0, c, -a * d);
        cout << ans.size() << '\n';
        for (auto [x, y] : ans) {
          cout << x << ' ' << y << '\n';
        }
      }
    } else if (c == 0) {
      if (d == 0) {
        infty();
      } else {
        vector<pll> ans = solve(a, b, 0, -a * d);
        cout << ans.size() << '\n';
        for (auto [x, y] : ans) {
          cout << x << ' ' << y << '\n';
        }
      }
    } else {
      if (b * c == a * d) {
        if (c % a != 0 && b % a != 0) {
          cout << 0 << '\n';
        } else {
          infty();
        }
      } else {
        vector<pll> ans = solve(a, b, c, b * c - a * d);
        cout << ans.size() << '\n';
        for (auto [x, y] : ans) {
          cout << x << ' ' << y << '\n';
        }
      }
    }
  }
}
