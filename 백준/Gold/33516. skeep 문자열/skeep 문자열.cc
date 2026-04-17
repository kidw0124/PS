#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <ext/rope>
using namespace __gnu_cxx;
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "
const string keep="keep";
bool check(crope&str, crope::iterator it, char c){
    if(it==str.mutable_end()) return false;
    return *it == c || *it == '#';
}

bool check(string&str, string::iterator it, char c){
    if(it==str.end()) return false;
    return *it == c || *it == '#';
}

bool is_pos(crope&str, crope::iterator it){
    for(char i : keep){
        if(!check(str, ++it, i)) return false;
    }
    return true;
}
bool is_pos(string&str, string::iterator it){
    for(char i : keep){
        if(!check(str, ++it, i)) return false;
    }
    return true;
}

void solve(ll testcase){
    int n;
    string _str;
    cin >>n>> _str;
    crope str(_str.c_str());
    // assign 's' location in str
    vector<crope::iterator> s_loc;
    int ans=0;
    auto it = str.mutable_end() - 1;
    while(true){
        if(*it=='s' && is_pos(str, it)){
            ans++;
            str.replace(it, it+5,"#");
            it++;
        }
        if(it==str.mutable_begin()) break;
        it--;
    }
    cout << ans << '\n';
}

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

signed main() {
    setup();
    preprocess();
    ll t = 1;
//    cin >> t;
#ifdef kidw0124
    clock_t st = clock();
#endif
    for (ll testcase = 1; testcase <= t; testcase++){
        solve(testcase);
    }
#ifdef kidw0124
    cout << "\n\nTime: " << (clock() - st) * 1.0 / CLOCKS_PER_SEC << "s\n";
#endif
    return 0;
}
