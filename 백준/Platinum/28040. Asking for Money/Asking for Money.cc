#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

void solve() {
    ll i,j,k;
    ll n;
    cin>>n;
    vector<pll>grp(n);
    vector<unordered_set<ll>>rgrp(n);
    string ans;
    for(i=0;i<n;i++){
        cin>>grp[i].first>>grp[i].second;
        grp[i].first--,grp[i].second--;
        rgrp[grp[i].first].insert(i);
        rgrp[grp[i].second].insert(i);
        ans+='N';
    }
    function<vector<bool>(ll,ll)> dfs=[&rgrp,&n](ll s, ll e)->vector<bool>{
        stack<ll>stk;
        stk.push(s);
        bool ret=0;
        vector<bool>vis(n);
        vis[s]=1;
        while(stk.size()){
            ll now=stk.top();
            stk.pop();
            for(auto k:rgrp[now]){
                if(vis[k]||k==e)continue;
                else{
                    vis[k]=1;
                    stk.push(k);
                }
            }
        }
        return vis;
    };
    for(i=0;i<n;i++){
        auto vis1=dfs(grp[i].first,i);
        auto vis2=dfs(grp[i].second,i);
        auto vis3=dfs(i,-1);
        for(j=0;j<n;j++){
            if(vis1[j]&&vis2[j]&&vis3[j])ans[i]='Y';
        }
    }
    cout<<ans;
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