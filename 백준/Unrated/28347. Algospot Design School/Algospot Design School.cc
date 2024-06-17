#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

#ifdef ONLINE_JUDGE
constexpr bool ddebug=false;
#else
constexpr bool ddebug=true;
#endif

constexpr ll mod = 1e9+7;

void preprocess(){
}

void solve(ll tc){
    ll n, m, p, q, r, s, i, j;
    char c;
    vector<pair<pll, pll>> fr, ba;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> p >> q >> r >> s >> c;
        if(c == 'F')fr.push_back({{p, q}, {r, s}});
        else ba.push_back({{p, q}, {r, s}});
    }

    n = fr.size();
    m = ba.size();

    vector<vector<vector<ll>>> adj(2);
    adj[0].resize(n);
    adj[1].resize(m);
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            bool flag1 = false, flag2 = false;
            ll s1, e1, s2, e2;
            s1 = fr[i].first.first;
            e1 = fr[i].second.first;
            s2 = ba[j].first.first;
            e2 = ba[j].second.first;
            if((e1 - s2) * (e2 - s1) > 0) {
                flag1 = true;
            }
            s1 = fr[i].first.second;
            e1 = fr[i].second.second;
            s2 = ba[j].first.second;
            e2 = ba[j].second.second;
            if((e1 - s2) * (e2 - s1) > 0) {
                flag2 = true;
            }
            if(flag1 && flag2) {
                adj[0][i].push_back(j);
                adj[1][j].push_back(i);
            }
        }
    }
//    for(i=0;i<n;i++){
//        cout<<i<<" : ";
//        for(auto k:adj[0][i])cout<<k<<' ';
//        cout<<'\n';
//    }
//    cout<<"BABO\n";
    vector<vector<bool>>vis(2);
    ll cnt=0;
    vis[0].resize(n),vis[1].resize(m);
    auto dfs=[&](ll x, ll y,auto&&dfs)->bool{
        vis[x][y]=1;
        for(auto k:adj[x][y]){
            if(vis[!x][k]||dfs(!x,k,dfs))continue;
            else{
                cnt++;
                return true;
            }
        }
        return false;
    };
    for(i=0;i<n;i++){
        if(!vis[0][i])dfs(0,i,dfs);
    }
    cout<<n+m-cnt<<'\n';
}

int main(){
    if(!ddebug){
        ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    }
    else{
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
    preprocess();
    ll t=1;
    cin>>t;
    for(ll i=0;i<t;i++)solve(i+1);
}