#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void setup() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
}
constexpr ll mod=1e9+7;

void solve(ll tc){
    ll i,j,k;
    ll n,m;
    cin>>n>>m;
    ll d=__lg(n);
    if((1<<d)!=n){
        cout<<"no";
        return;
    }
    vector<unordered_set<ll>>grp(n+1);
    vector<pair<ll,ll>>vct;
    for(i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        grp[a].insert(b),grp[b].insert(a);
        vct.push_back({a,b});
    }
    for(i=1;i<=n;i++){
        if(grp[i].size()!=d){
            cout<<"no";
            return;
        }
    }
    vector<ll>idx(n+1,-1);
    idx[1]=0;
    ll nowd=0;
    queue<ll>que;
    for(auto&x:grp[1]){
        idx[x]=1<<nowd++;
        grp[x].erase(1);
        que.push(x);
    }
    while(!que.empty()){
        ll now=que.front();
        que.pop();
        for(auto&x:grp[now]){
            if(idx[x]==-1){
                idx[x]=0;
                que.push(x);
            }
            idx[x]|=idx[now];
            grp[x].erase(now);
        }
    }
    for(auto&[a,b]:vct){
        if(__builtin_popcountll(idx[a]^idx[b])!=1){
            cout<<"no";
            return;
        }
    }
    cout<<"yes";
}

void preprocess(){
    ll i,j,k;
}

int main(){
    setup();preprocess();
    ll t=1;
//    cin>>t;
    for(ll i=0;i<t;i++){
        solve(t+1);
    }
    return 0;
}