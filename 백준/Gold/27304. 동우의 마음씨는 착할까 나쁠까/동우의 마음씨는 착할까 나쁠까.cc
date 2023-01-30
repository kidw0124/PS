//
// Created by kidw0 on 2022-12-31.
//
#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
typedef long long ll;
typedef unsigned long long ull;
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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
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

int main() {
    setup();
    ll i, j;
    ll n;
    cin >> n;
    vector<vector<pll>> edges(n + 1);
    vector<ll> depth(n + 1), par(n + 1), des(n + 1, 0), dis(n + 1), ans(n + 1), cost(n + 1);
    vector<bool> vis(n + 1);
    for (i = 0; i < n - 1; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    stack<ll> stk;
    depth[1] = 1;
    stk.push(1);
    while (!stk.empty()) {
        ll now = stk.top();
        stk.pop();
        for (auto [p, c] : edges[now]) {
            if (par[now] != p) {
                depth[p] = depth[now] + 1;
                par[p] = now;
                cost[p] = c;
                stk.push(p);
            }
        }
    }
    priority_queue<pll> pq;
    for (i = 2; i <= n; i++) {
        if (edges[i].size() == 1) {
            pq.push({depth[i], i});
            des[i] = 1;
        }
    }
    while (!pq.empty()) {
        auto [d, now] = pq.top();
        pq.pop();
        if (!des[par[now]]) {
            des[par[now]] = 1 + des[now];
            pq.push({depth[par[now]], par[now]});
        } else {
            des[par[now]] += des[now];
        }
    }
    for (i = 2; i <= n; i++) {
        if (edges[i].size() == 1) {
            pq.push({depth[i], i});
            dis[i] = 0;
            vis[i] = true;
        }
    }
    while (!pq.empty()) {
        auto [d, now] = pq.top();
        pq.pop();
        if (!vis[par[now]]) {
            vis[par[now]] = 1;
            pq.push({depth[par[now]], par[now]});
            dis[par[now]] = des[now] * cost[now] + dis[now];
        } else {
            dis[par[now]] += des[now] * cost[now] + dis[now];
        }
    }
    std::fill(vis.begin(), vis.end(), 0);
    ans[1] = dis[1];
    for (auto [p, c] : edges[1]) {
        ans[p] = ans[1] + n * cost[p] - 2 * cost[p] * des[p];
        stk.push(p);
    }
    while (!stk.empty()) {
        ll now = stk.top();
        stk.pop();
        for (auto [p, c] : edges[now]) {
            if (par[now] != p) {
                ans[p] = ans[now] + n * cost[p] - 2 * cost[p] * des[p];
                stk.push(p);
            }
        }
    }
    cout << *min_element(ans.begin() + 1, ans.end()) << ' ' << *max_element(ans.begin() + 1, ans.end()) << '\n';
    // debugc(ans);
    return 0;
}
