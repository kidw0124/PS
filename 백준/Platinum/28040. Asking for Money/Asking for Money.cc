#include <bits/stdc++.h>
using namespace std;

void solve() {
    int i,j;
    int n;
    cin>>n;
    vector<pair<int,int>>grp(n+1);
    vector<vector<int>>rgrp(n+1);
    string ans;
    for(i=1;i<=n;i++){
        cin>>grp[i].first>>grp[i].second;
        rgrp[grp[i].first].push_back(i);
        rgrp[grp[i].second].push_back(i);
    }
    function<vector<bool>(int,int)> dfs=
            [&rgrp,&n](int s, int inter)->vector<bool>{
        stack<int>stk;
        stk.push(s);
        vector<bool>vis(n+1);
        vis[s]=1;
        while(stk.size()){
            int now=stk.top();
            stk.pop();
            for(auto k:rgrp[now]){
                if(vis[k]||k==inter)continue;
                else{
                    vis[k]=1;
                    stk.push(k);
                }
            }
        }
        return vis;
    };
    for(i=1;i<=n;i++){
        auto vis1=dfs(grp[i].first,i);
        auto vis2=dfs(grp[i].second,i);
        auto vis3=dfs(i,-1);
        for(j=1;j<=n;j++){
            if(vis1[j]&&vis2[j]&&vis3[j]){
                ans+='Y';
                break;
            }
        }
        if(j==n+1)ans+='N';
    }
    cout<<ans;
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