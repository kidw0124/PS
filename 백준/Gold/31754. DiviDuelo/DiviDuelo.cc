#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using namespace std;

auto get_fac = [](ll n) {
    vector res(0, pair(0LL, 0LL));
    for (ll i = 2; i * i <= n; i++) {
        if (n % i) continue;
        int cnt = 0;
        while (n % i == 0) n /= i, cnt++;
        res.push_back({ i, cnt });
    }
    if (n > 1) res.push_back({ n, 1 });
    return res;
};

void solve() {
    ll n; cin >> n;
    for(ll i=1;i*i<=n;i++){
        if(i*i==n){
            cout<<"N\n";
            return;
        }
    }
    auto fac = get_fac(n);
    if (fac.size() == 1) cout << 'Y' << '\n';
    else if (fac.size() == 2 && fac[0].second == 1 && fac[1].second == 1) cout << 'Y' << '\n';
    else cout << 'N' << '\n';
}

int main() {
    fastio;
    solve();
}