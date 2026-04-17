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

void setup(){
    if(ddebug){
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
    else{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void solve() {
    ll n, m, i, p, q;
    bool missing = false, recheck = false;
    cin >> n >> m;
    vector<ll> cnt(n), res;
    stack<ll> zero;
    vector<vector<ll>> path(n);
    for(i  = 0; i < m; i++) {
        cin >> p >> q;
        p--;
        q--;
        cnt[p]++;
        path[q].push_back(p);
    }

    for(i = 0; i < n; i++) {
        if(cnt[i] == 0)zero.push(i);
    }

    while(res.size() < n) {
        if(zero.size() > 1)missing = true;
        if(zero.size() == 0) {
            recheck = true;
            break;
        }
        p = zero.top();
        zero.pop();
        res.push_back(p);
        for(i = 0; i < path[p].size(); i++) {
            cnt[path[p][i]]--;
            if(cnt[path[p][i]] == 0)zero.push(path[p][i]);
        }
    }

    if(recheck)cout << "recheck hints\n";
    else if(missing)cout << "missing hints\n";
    else {
        for(i = n - 1; i >= 0; i--)cout << res[i] + 1 << " ";
        cout << "\n";
    }
}

int main(){
    setup();
    ll t;
    cin >> t;
    for(ll tc = 0; tc < t; tc++) {
        solve();
    }
}