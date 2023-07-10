#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
typedef long long ll;
typedef double ld;

using ll = long long;
using pld=pair<ld,ld>;
using segment = pair<pld,pld>;

void get_components(vector<string> board, vector<vector<pair<ll, ll>>>& components) {
    vector<vector<bool>> vis(12, vector<bool>(6));
    for(ll i = 0; i < 12; i++) {for(ll j = 0; j < 6; j++) if(board[i][j] == '.') vis[i][j] = true;}
    ll dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    for(ll i = 0; i < 12; i++) {
        for (ll j = 0; j < 6; j++) {
            if (vis[i][j]) continue;
            vis[i][j] = true;
            char target = board[i][j];
            stack<pair<ll, ll>> stk;
            stk.push({i, j});
            vector<pair<ll, ll>> temp_arr;
            while(stk.size()) {
                auto [a, b] = stk.top();
                stk.pop();
                temp_arr.push_back({a, b});
                for(ll k = 0; k < 4; k++) {
                    if(a + dx[k] < 0 || a + dx[k] >= 12 || b + dy[k] < 0 || b + dy[k] >= 6) continue;
                    if(vis[a + dx[k]][b + dy[k]] || board[a + dx[k]][b + dy[k]] != target) continue;
                    vis[a + dx[k]][b + dy[k]] = true;
                    stk.push({a + dx[k], b + dy[k]});
                }
            }
            if(temp_arr.size() >= 4) components.push_back(temp_arr);
        }
    }
}

void erase_and_apply_gravity(vector<string>& board, vector<vector<pair<ll, ll>>>& components) {
    for(auto component : components) {
        for(auto [a, b] : component) {
            board[a][b] = '.';
        }
    }
    components = vector<vector<pair<ll, ll>>>();
    for(ll j = 0; j < 6; j++) {
        ll i;
        for(i = 11; i >= 0; i--) {
            if(board[i][j] == '.') break;
        }
        if(i > 0) {
            ll moveto = i;
            for (ll i = moveto - 1; i >= 0; i--) {
                if (board[i][j] != '.') {
                    board[moveto--][j] = board[i][j];
                    board[i][j] = '.';
                }
            }
        }
    }
}

void solve()
{
    ll i,j;
    string str;
    vector<string> board(12);
    for(i = 0; i < 12; i++) {cin >> str; board[i] = str;}

    ll ans = 0;
    vector<vector<pair<ll, ll>>> components;
    get_components(board, components);
    while(components.size()) {
        ans += 1;
        erase_and_apply_gravity(board, components);
        get_components(board, components);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t=1;
//    cin >> t;
    while(t--)solve();

    return 0;
}