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

bool cmp(const pll&a,const pll&b){
    return b.first*a.second<a.first*b.second;
}

pll operator-(const pll&b, const pll&a){
    return {b.first-a.first,b.second-a.second};
}

ll ccw(pll a,pll b){
    return a.first*b.second-a.second*b.first;
}

ll ccw(const pll a,const pll b,const pll c){
    return ccw(b-a,c-a);
}

ll dist(const pll&a, const pll&b){
    pll d=b-a;
    return d.first*d.first+d.second*d.second;
}
ll dist(const pll&a){
    return dist({0,0},a);
}

void solve(ll testcase){
    ll i,j,k;
    ll n,m;
    cin>>n>>m;
    if(n==0&&m==0)exit(0);
    cout<<"Case "<<testcase<<": ";
    vector<vector<ll>>edges(n+1);
    vector<ll>vis(n+1),par(n+1);
    for(i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    ll cnt=0;
    for(i=1;i<=n;i++){
        if(!vis[i]){
            cnt++;
            bool tr=0;
            stack<ll>stk({i});
            vis[i]=1;
            while(!stk.empty()){
                ll now=stk.top();
                stk.pop();
                for(auto k:edges[now]){
                    if(k==par[now])continue;
                    if(!vis[k]){
                        stk.push(k);
                        par[k]=now;
                        vis[k]=1;
                    }
                    else {
                        tr=1;
                    }
                }
            }
            if(tr)cnt--;
        }
    }
    if(cnt==0){
        cout<<"No trees.\n";
    }
    else if(cnt==1){
        cout<<"There is one tree.\n";
    }
    else{
        cout<<"A forest of "<<cnt<<" trees.\n";
    }
}

int main() {
    setup();
    ll t=INT_MAX;
    //cin>>t;
    for(ll testcase=1;testcase<=t;testcase++) {
        solve(testcase);
    }
    return 0;
}
