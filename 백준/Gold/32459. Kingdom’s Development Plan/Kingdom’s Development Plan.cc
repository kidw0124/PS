#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j;
    ll n,m;
    cin>>n>>m;
    vector<set<ll>>grp(n+1),rgrp(n+1);
    for(i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        grp[y].insert(x);
        rgrp[x].insert(y);
    }
    priority_queue<ll>que;
    for(i=1;i<=n;i++){
        if(grp[i].size()==0)que.push(-i);
    }
    vector<ll>arr;
    while(!que.empty()){
        ll now=-que.top();
        que.pop();
        arr.push_back(now);
        for(auto k:rgrp[now]){
            grp[k].erase(now);
            if(grp[k].size()==0)que.push(-k);
        }
    }
    if(arr.size()==n)for(auto k:arr)cout<<k<<' ';
    else cout<<"IMPOSSIBLE\n";
}