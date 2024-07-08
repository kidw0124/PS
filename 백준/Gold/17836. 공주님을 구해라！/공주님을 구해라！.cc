#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

void solve() {
    int i,j;
    int n,m,r;
    cin >> n >> m>>r;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int>dx({-1,1,0,0}), dy({0,0,-1,1});
    pii des;
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 2) des = {i,j};
        }
    }
    auto bfs = [&n,&m,&dx,&dy,&a](pii s, pii e){
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pii> q;
        q.push(s);
        dist[s.first][s.second] = 0;
        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(dist[nx][ny] != -1 || a[nx][ny] == 1) continue;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx,ny});
            }
        }
        return dist[e.first][e.second]==-1?10001:dist[e.first][e.second];
    };
    int ans=min(bfs({0,0},des)+n-1+m-1-des.first-des.second
            , bfs({0,0},{n-1,m-1}));
    if(ans<=r)cout<<ans;
    else cout<<"Fail";
}

int main() {
#ifdef kidw0124
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    int t = 1;
    //cin >> t;
    while (t--) solve();
}