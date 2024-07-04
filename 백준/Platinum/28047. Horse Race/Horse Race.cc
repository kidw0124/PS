#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

void solve() {
    ll i,j,k;
    ll n;
    cin>>n;
    vector<string>str(n);
    unordered_map<string,ll>mp;
    for(i=0;i<n;i++){
        cin>>str[i];
        mp[str[i]]=i;
    }
    vector<unordered_set<ll>>pos(n+1);
    for(i=1;i<=n;i++){
        for(j=0;j<n;j++){
            pos[i].insert(j);
        }
    }
    vector<vector<bool>>impos(n,vector<bool>(n+1));
    ll m=0;
    cin>>m;
    for(i=0;i<m;i++){
        ll a;
        cin>>a;
        ll rnk;
        cin>>rnk;
        unordered_set<ll>st;
        for(j=0;j<a;j++){
            string b;
            cin>>b;
            st.insert(mp[b]);
        }
        for(auto b:st){
            for(j=1;j<rnk;j++){
                impos[b][j]=1;
            }
        }
        auto sts=pos[rnk];
        for(auto x:sts){
            if(st.find(x)==st.end()){
                pos[rnk].erase(x);
            }
        }
    }
    vector<ll>ans(n);
    for(i=1;i<=n;i++){
        for(auto can:pos[i]){
            if(!ans[can] && !impos[can][i]){
                ans[can]=i;
                break;
            }
        }
    }
    for(i=1;i<=n;i++){
        cout<<str[find(ans.begin(), ans.end(),i)-ans.begin()]<<' ';
    }
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