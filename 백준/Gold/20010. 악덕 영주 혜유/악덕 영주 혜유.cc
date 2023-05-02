#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef __float128 LD;
typedef __int128_t LL;
typedef __uint128_t ULL;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()

void setup(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

//ll n;
//vector<ll>arr;
//void func(ll rsum, ll sum, ll now, vector<vector<vector<ll>>>&a,vector<ll>b){
//    if(now==n-1){
//        for(ll i=0;i<=min(sum,arr[now]);i++){
//            b.push_back(i);
//            a[rsum+i].push_back(b);
//            b.pop_back();
//        }
//    }
//    else{
//        for(ll i=0;i<=min(sum,arr[now]);i++){
//            b.push_back(i);
//            func(rsum+i, sum-i,now+1,a,b);
//            b.pop_back();
//        }
//    }
//}

vector<ll>grp;

ll _find(ll x){
    if(x==grp[x])return x;
    else return grp[x]=_find(grp[x]);
}

void _union(ll x,ll y){
    x=_find(x);
    y=_find(y);
    grp[x]=y;
}

void solve(){
    ll i,j,k;
    ll n,m,ans=0;
    cin>>n>>m;
    grp.resize(n);
    vector<vector<pll>>edge(n),tree(n);
    priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<>>edge2;
    for(i=0;i<m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        edge[x].push_back({y,z});
        edge[y].push_back({x,z});
        edge2.push({z,x,y});
    }
    iota(all(grp),0);
    while(!edge2.empty()){
        auto [z,x,y]=edge2.top();
        edge2.pop();
        if(_find(x)==_find(y))continue;
        else{
            ans+=z;
            tree[x].push_back({y,z});
            tree[y].push_back({x,z});
            _union(x,y);
        }
    }
    cout<<ans<<' ';
    vector<ll>dist(n,-1),dist2(n,-1);
    stack<ll>stk({0});
    dist[0]=0;
    while(!stk.empty()){
        ll now=stk.top();
        stk.pop();
        for(auto [k,kk]:tree[now]){
            if(dist[k]==-1){
                dist[k]=dist[now]+kk;
                stk.push(k);
            }
        }
    }
    ll ma= max_element(all(dist))-dist.begin();
    stk.push(ma);
    dist2[ma]=0;
    while(!stk.empty()){
        ll now=stk.top();
        stk.pop();
        for(auto [k,kk]:tree[now]){
            if(dist2[k]==-1){
                dist2[k]=dist2[now]+kk;
                stk.push(k);
            }
        }
    }
    cout<<*max_element(all(dist2));

}

int main() {
    setup();
    ll t=1;
    //cin>>t;
    for(ll testcase=1;testcase<=t;testcase++) {
        solve();
    }
    return 0;
}
