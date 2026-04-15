#include <bits/stdc++.h>
#include <immintrin.h>
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
using ll = long long;
using pll = pair<ll, ll>;
#define debug \
  if constexpr (ddebug) cout << "[DEBUG] "
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ld= long double;
const ll mod=1e9+7;
constexpr ll MAXN=1e6;

string calculate_pi(const string& str, ll x) {
    string ret;
    vector<ll>bef;
    vector<ll>pi(str.size());
    pi[0] = -1;
    for (ll i = 1, j = -1; i < str.size(); i++) {
        while (j >= 0 && str[i] != str[j + 1]) j = pi[j];
        if (str[i] == str[j + 1]) pi[i] = ++j;
        else pi[i] = -1;
        bef.push_back(j);
        if (i>=x+1) {
            ret+=str[i];
            if (pi[i]==x-1) {
                for (ll k=0;k<x;k++)ret.pop_back(),bef.pop_back();
                j=bef.back();
            }
        }
    }
    return ret;
}

void solve(ll testcase) {
    ll i,j;
    ll n,m;
    if (cin>>n) {
        string str;
        cin>>str;
        cin.ignore();
        while (n--) {
            string line;
            getline(cin,line);
            cout<<calculate_pi(str+"\n"+line,str.size());
            cout<<'\n';
        }
        solve(testcase+1);
    }
    else exit(0);
}

void setup() {
    if (ddebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    } else {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void preprocess() {
    ll i, j, k;
}

signed main() {
    setup();
    preprocess();
    ll t = 1;
    // cin >> t;
    for (ll testcase = 1; testcase <= t; testcase++) {
        solve(testcase);
    }
    return 0;
}
