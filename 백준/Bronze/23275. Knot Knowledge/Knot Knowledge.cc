#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif

#define debug if(ddebug)cout << "[DEBUG] "
#define debugv(x) debug << #x << " : " << x << "\n";

using ll = long long;
using ld = long double;
using LL = __int128_t;
using pll = pair<ll, ll>;

void setup() {
    if(ddebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    else {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
}

void preprocess() {
    ll i, j;
}

void solve(ll testcase) {
    ll i, j;
//    pll a, b, c, d;
//    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;
    ll n;
    cin>>n;
    set<ll>st;
    for(i=0;i<n;i++){
        cin>>j;
        st.insert(j);
    }
    for(i=0;i<n;i++){
        cin>>j;
        st.erase(j);
    }
    cout<<*st.begin();
}

int main() {
    setup();
    preprocess();
    ll t = 1;
//    cin >> t;
    for(ll i = 1; i <= t; i++)solve(i);
    return 0;
}