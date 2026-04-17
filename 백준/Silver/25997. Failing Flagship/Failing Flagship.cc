#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using ld = long double;
using pld = pair<ld, ld>;


#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (ddebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugc(c) if constexpr (ddebug) { cout << "[DEBUG] " << #c << ": "; for (const auto& elem : c) cout << elem << ", "; cout << '\n'; }

#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto &x : a)

void setup() {
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
    ll i, j, k;
}

ld calc(string s) {
    if(s.size() == 1) {
        if(s[0] == 'N')return 0;
        if(s[0] == 'E')return 90;
        if(s[0] == 'S')return 180;
        if(s[0] == 'W')return 270;
    }
    ll n = s.size();
    ld ret = 0, cur = 22.5;
    if(s[n - 1] == 'E') {
        if(s[n - 2] == 'N') {
            ret = 45;
            for(ll k = n - 3; k >= 0; k--) {
                if(s[k] == 'N')ret -= cur;
                else ret += cur;
                cur /= 2;
            }
        }
        else {
            ret = 135;
            for(ll k = n - 3; k >= 0; k--) {
                if(s[k] == 'E')ret -= cur;
                else ret += cur;
                cur /= 2;
            }
        }
    }
    else {
        if(s[n - 2] == 'S') {
            ret = 225;
            for(ll k = n - 3; k >= 0; k--) {
                if(s[k] == 'S')ret -= cur;
                else ret += cur;
                cur /= 2;
            }
        }
        else {
            ret = 315;
            for(ll k = n - 3; k >= 0; k--) {
                if(s[k] == 'W')ret -= cur;
                else ret += cur;
                cur /= 2;
            }
        }
    }

    return ret;
}

void solve(ll testcase) {
    string a, b;
    ld res;
    cin >> a >> b;
    res = calc(a) - calc(b);
    if(res < 0)res = -res;
    if(res > 180)res = 360 - res;
    cout << fixed << setprecision(12) << res;
}

int main()
{
    setup();
    preprocess();
    ll t = 1;
//    cin >> t;
    for(ll testcase = 1; testcase <= t; testcase++) {
        solve(testcase);
    }
    return 0;
}