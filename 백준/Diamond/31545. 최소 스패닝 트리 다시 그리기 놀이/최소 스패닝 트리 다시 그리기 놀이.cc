#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using ld =   __float128;
using pld = pair<ld,ld>;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto &x : a)
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "

#ifndef kidw0124
const ll TSIZE = 1 << 20; // always 2^k form && n <= TSIZE
#else
const ll TSIZE = 1 << 3; // always 2^k form && n <= TSIZE
#endif

void setup()
{
    if(ddebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    else {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void preprocess() {
    ll i, j;


}

// extended euclidean algorithm and modular inverse
ll gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll modinv(ll a, ll m) {
    ll x, y;
    ll g = gcd(a, m, x, y);
    if (g != 1) {
        return -1;
    } else {
        x = (x % m + m) % m;
        return x;
    }
}

const ll mod = 1e9+7;

template <ll mod = mod>
struct Z{
    ll x;
    Z(ll x = 0) : x(x) {}
    Z operator+(const Z& y) const { return Z((x+y.x)%mod); }
    Z operator-(const Z& y) const { return Z((x-y.x+mod)%mod); }
    Z operator*(const Z& y) const { return Z(x*y.x%mod);}
    Z operator/(const Z& y) const { return *this * modinv(y.x, mod); }
    Z& operator+=(const Z& y) { return *this = *this + y; }
    Z& operator-=(const Z& y) { return *this = *this - y; }
    Z& operator*=(const Z& y) { return *this = *this * y; }
    Z& operator/=(const Z& y) { return *this = *this / y; }
    Z operator-() const { return Z(-x); }
    bool operator==(const Z& y) const { return x == y.x; }
    bool operator!=(const Z& y) const { return x != y.x; }
    friend ostream& operator<<(ostream& os, const Z& z) { return os << z.x; }
    friend istream& operator>>(istream& is, Z& z) { return is >> z.x; }
};

template <typename T = Z<>>
struct Matrix {
    ll size;
    vector<vector<T>> a;
    Matrix(ll size) : size(size), a(size, vector<T>(size)) {}
    Matrix Erase_last_row_and_column() {
        Matrix<T> ret(size-1);
        for(ll i = 0; i < size-1; i++) {
            for(ll j = 0; j < size-1; j++) {
                ret.a[i][j] = a[i][j];
            }
        }
        return ret;
    }
    T det() {
        // Gaussian elimination
        T res = 1;
//        debug << *this;
//        debug << "Start Gaussian elimination\n";
        for (ll i = 0; i < size; i++) {
            debug << "i: " << i << '\n';
            for (ll j = i ; j < size; j++) {
                if (a[j][i] != 0) {
                    if (i != j) {
                        swap(a[i], a[j]);
                        res = -res;
                    }
                    break;
                }
            }
            if (a[i][i] == 0) {
                return 0;
            }
            res *= a[i][i];
            for(ll j = i+1; j < size; j++) {
                T ratio = a[j][i] / a[i][i];
                for(ll k = i; k < size; k++) {
                    a[j][k] -= a[i][k] * ratio;
                }
            }
        }
        return res;
    }
};

ostream &operator<<(ostream &os, const Matrix<Z<>> &m) {
    for (ll i = 0; i < m.size; i++) {
        for (ll j = 0; j < m.size; j++) {
            os << m.a[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}

vector<ll> grp;

ll _find(ll x){
    if(grp[x] == x) return x;
    return grp[x] = _find(grp[x]);
}

void _union(ll x, ll y){
    x = _find(x);
    y = _find(y);
    if(x != y) grp[x] = y;
}

void solve(ll testcase){
    ll i, j, k;
    ll v,e;
    cin >> v >> e;
    map<int, vector<pii>> edges;
    for(i = 0; i < e; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        edges[w].push_back({a, b});
    }
    grp.resize(v+1);
    iota(all(grp), 0);
    Z ans=1;
    for(auto &[w,es]:edges){
        Z pans=1;
        unordered_map<int,vector<int>>vertices;
        unordered_map<int,unordered_set<int>>rgrp;
        for(auto [a,b]:es){
            _find(a), _find(b);
            if(_find(a) != _find(b)){
                vertices[_find(a)].push_back(_find(b));
                vertices[_find(b)].push_back(_find(a));
            }
        }
        for(auto [a,b]:es){
            if(_find(a) != _find(b)){
                _union(a,b);
            }
        }
        for(const auto&[v,vec]:vertices){
            rgrp[_find(v)].insert(v);
        }
        for(const auto&[v,sets]:rgrp){
            Matrix<Z<>> m(sets.size());
            map<int,int>mp;
            int idx = 0;
            for(auto x:sets){
                mp[x] = idx++;
            }
            for(auto x:sets){
                m.a[mp[x]][mp[x]] = vertices[x].size();
                for(auto y:vertices[x]){
                    m.a[mp[x]][mp[y]] -= 1;
                }
            }
            pans *= m.Erase_last_row_and_column().det();
        }
        Z z_w = w;
        ans *= (pans + z_w - Z(1)) / z_w;
    }
    cout << ans << '\n';


}

int main()
{
    setup();
    preprocess();
    ll t = 1;
//    cin >> t;
    for (ll testcase = 1; testcase <= t; testcase++)
    {
        solve(testcase);
    }
    return 0;
}
