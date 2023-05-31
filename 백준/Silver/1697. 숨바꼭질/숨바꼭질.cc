#include<bits/stdc++.h>
using ll = long long;
using namespace std;

ll n,m;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll i,j,k;
    cin>>n>>m;
    ll ans=0;
    queue<pair<ll,ll>>que({{n,0ll}});
    set<ll>vis({n});
    while(1){
        auto [p,lev]=que.front();
        que.pop();
        if(p==m){
            cout<<lev;
            return 0;
        }
        if(p>0 and vis.find(p-1)==vis.end())que.push({p-1,lev+1}),vis.insert(p-1);
        if(vis.find(p+1)==vis.end())que.push({p+1,lev+1}),vis.insert(p+1);
        if(2*p<=100000 and vis.find(2*p)==vis.end())que.push({2*p,lev+1}),vis.insert(p+p);
    }
}
