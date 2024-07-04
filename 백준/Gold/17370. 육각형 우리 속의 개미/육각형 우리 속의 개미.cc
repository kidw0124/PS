#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll,ll>;

set<pll> st;
ll res;

void dfs(pll cur, ll dir, ll cnt, ll n) {
    if(cnt == n)return;
    if(dir == 1) {
        if(st.find({cur.first + 1, cur.second + 1}) == st.end()) {
            st.insert({cur.first + 1, cur.second + 1});
            dfs({cur.first + 1, cur.second + 1}, 3, cnt + 1, n);
            st.erase({cur.first + 1, cur.second + 1});
        }
        else if(cnt + 1 == n)res++;


        if(st.find({cur.first - 1, cur.second + 1}) == st.end()) {
            st.insert({cur.first - 1, cur.second + 1});
            dfs({cur.first - 1, cur.second + 1}, 5, cnt + 1, n);
            st.erase({cur.first - 1, cur.second + 1});
        }
        else if(cnt + 1 == n)res++;
    }

    else if(dir == 2) {
        if(st.find({cur.first - 1, cur.second - 1}) == st.end()) {
            st.insert({cur.first - 1, cur.second - 1});
            dfs({cur.first - 1, cur.second - 1}, 4, cnt + 1, n);
            st.erase({cur.first - 1, cur.second - 1});
        }
        else if(cnt + 1 == n)res++;


        if(st.find({cur.first + 1, cur.second - 1}) == st.end()) {
            st.insert({cur.first + 1, cur.second - 1});
            dfs({cur.first + 1, cur.second - 1}, 6, cnt + 1, n);
            st.erase({cur.first + 1, cur.second - 1});
        }
        else if(cnt + 1 == n)res++;
    }

    else if(dir == 3) {
        if(st.find({cur.first, cur.second + 2}) == st.end()) {
            st.insert({cur.first, cur.second + 2});
            dfs({cur.first, cur.second + 2}, 1, cnt + 1, n);
            st.erase({cur.first, cur.second + 2});
        }
        else if(cnt + 1 == n)res++;


        if(st.find({cur.first + 1, cur.second - 1}) == st.end()) {
            st.insert({cur.first + 1, cur.second - 1});
            dfs({cur.first + 1, cur.second - 1}, 6, cnt + 1, n);
            st.erase({cur.first + 1, cur.second - 1});
        }
        else if(cnt + 1 == n)res++;
    }

    else if(dir == 4) {
        if(st.find({cur.first, cur.second - 2}) == st.end()) {
            st.insert({cur.first, cur.second - 2});
            dfs({cur.first, cur.second - 2}, 2, cnt + 1, n);
            st.erase({cur.first, cur.second - 2});
        }
        else if(cnt + 1 == n)res++;


        if(st.find({cur.first - 1, cur.second + 1}) == st.end()) {
            st.insert({cur.first - 1, cur.second + 1});
            dfs({cur.first - 1, cur.second + 1}, 5, cnt + 1, n);
            st.erase({cur.first - 1, cur.second + 1});
        }
        else if(cnt + 1 == n)res++;
    }

    else if(dir == 5) {
        if(st.find({cur.first, cur.second + 2}) == st.end()) {
            st.insert({cur.first, cur.second + 2});
            dfs({cur.first, cur.second + 2}, 1, cnt + 1, n);
            st.erase({cur.first, cur.second + 2});
        }
        else if(cnt + 1 == n)res++;


        if(st.find({cur.first - 1, cur.second - 1}) == st.end()) {
            st.insert({cur.first - 1, cur.second - 1});
            dfs({cur.first - 1, cur.second - 1}, 4, cnt + 1, n);
            st.erase({cur.first - 1, cur.second - 1});
        }
        else if(cnt + 1 == n)res++;
    }

    else {
        if(st.find({cur.first, cur.second - 2}) == st.end()) {
            st.insert({cur.first, cur.second - 2});
            dfs({cur.first, cur.second - 2}, 2, cnt + 1, n);
            st.erase({cur.first, cur.second - 2});
        }
        else if(cnt + 1 == n)res++;

        if(st.find({cur.first + 1, cur.second + 1}) == st.end()) {
            st.insert({cur.first + 1, cur.second + 1});
            dfs({cur.first + 1, cur.second + 1}, 3, cnt + 1, n);
            st.erase({cur.first + 1, cur.second + 1});
        }
        else if(cnt + 1 == n)res++;
    }
}

void solve() {
    ll n;
    cin >> n;

    st.insert({0, 0});
    st.insert({0, 2});
    dfs({0, 2}, 1, 0, n);

    cout << res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    int t = 1;
    //cin >> t;
    while (t--) solve();
}