//
// Created by kidw0 on 2022-12-31.
//
#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
typedef unsigned long long ll;
typedef __int128_t LL;
typedef __uint128_t ULL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto& x : a)
#define endl '\n'

#define debug \
    if constexpr (xdebug) cout << "[DEBUG] "
#define debugv(x) \
    if constexpr (xdebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugc(c)                                        \
    if constexpr (xdebug) {                              \
        cout << "[DEBUG] " << #c << ": ";                \
        for (const auto& elem : c) cout << elem << ", "; \
        cout << '\n';                                    \
    }

#ifndef ONLINE_JUDGE
constexpr bool xdebug = true;
#else
constexpr bool xdebug = false;
#endif
void setup() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
#endif
}
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) {
    if (a && b) return a * (b / gcd(a, b));
    return a + b;
}
ll powm(ll a, ll b, ll rem) {
    ll p = 1;
    for (; b; b /= 2, a = (a * a) % rem)
        if (b & 1) p = (p * a) % rem;
    return p;
}

std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}
ll mod = 1e9 + 7;
int main() {
    setup();
    ll i, j;
    ll t;
    cin >> t;
    while (t--) {
        LL n, m;
        ll ln,lm;
        cin >> ln >> lm;
        n=ln,m=lm;
        LL p, q, g;
        p = 2 * m * n + m + n;
        q = m + n;
        if (p % q == 0) {
            cout << p / q << ' ';
        } else {
            g = gcd(p, q);
            cout << p / g << '/' << q / g << ' ';
        }
        p = 2 * m * n * (2 * m * n - m - n);
        q = (m + n) * (m + n) * (m + n - 1);
        if (p == 0) {
            cout << 0 << ' ';
        } else if (p % q == 0) {
            cout << p / q << ' ';
        } else {
            g = gcd(p, q);
            cout << p / g << '/' << q / g << ' ';
        }
        p = 2 * m * n;
        q = m + n - 1;
        if (p == 0) {
            cout << 1 << ' ';
        } else if (p % q == 0) {
            cout << p / q << ' ';
        } else {
            g = gcd(p, q);
            cout << p / g << '/' << q / g << ' ';
        }
        p = 4 * m * n * (m * n - m - n + 1);
        q = (m + n - 1) * (m + n - 1) * (m + n - 2);
        if (m + n <= 2) {
            cout << 0 << '\n';
        } else if (p % q == 0) {
            cout << p / q << '\n';
        } else {
            g = gcd(p, q);
            cout << p / g << '/' << q / g << '\n';
        }
    }
    return 0;
}