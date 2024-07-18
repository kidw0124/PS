#include<bits/stdc++.h>
using namespace std;
using ll = int;
using pll = pair<ll,ll>;
using tlll = tuple<ll,ll,ll>;
int main(){
    ll i,j,k;
    ll n,m;
    cin>>n>>m;
    vector<string>str(n);
    for(i=0;i<n;i++)cin>>str[i];
    ll ans=0;
    stack<pair<pll,ll>>q;
    q.push({{0,0},1<<(str[0][0]-'a')});
    while(!q.empty()) {
        auto [pos, mask] = q.top();
        q.pop();
        auto [x, y] = pos;
        ans = max(ans, (ll)__builtin_popcount(mask));
        for (auto [dx, dy]: vector<pll>{{1,  0},
                                        {0,  1},
                                        {-1, 0},
                                        {0,  -1}}) {
            ll nx = x + dx, ny = y + dy;
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
            if (mask & (1 << (str[nx][ny] - 'a')))continue;
            ll nmask = mask | (1 << (str[nx][ny] - 'a'));
            q.push({{nx, ny}, nmask});
        }
    }
    cout<<ans<<endl;

}