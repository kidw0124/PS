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
using pld = pair<ld, ld>;

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

ld dist(pld a, pld b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
const ll MAXT=5000;
bool arr[MAXT][MAXT];
void solve(ll testcase) {
    srand(time(0));
    ll i, j,k;
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), plus(n, 1e18), minus(n, 1e18), res(n);
    for(i = 0; i < n; i++) {
        cin >> a[i];
        plus[i] = a[i] - m * i;
        minus[i] = -a[i] - m * i;
        if(i == 0)continue;
        res[i] = max(plus[i] - plus[i - 1], minus[i] - minus[i - 1]);
        plus[i] = min(plus[i], plus[i - 1]);
        minus[i] = min(minus[i], minus[i - 1]);
    }
    for(i = 0; i < n; i++)cout << max(0ll, res[i]) << " ";
}

int main() {
    setup();
    preprocess();
    ll t = 1;
//    cin >> t;
    for(ll i = 1; i <= t; i++)solve(i);
    return 0;
}