#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#ifdef ONLINE_JUDGE
constexpr bool XDEBUG = false;
#else
constexpr bool XDEBUG = true;
#endif


void setup(){
    if(XDEBUG){
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
    else{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void preprocess(){
    ll i,j,k;
}

set<set<ll>>pos;
vector<set<ll>>vct;
bitset<56>vis;
vector<vector<ll>>arr(8,vector<ll>(7));
vector<vector<ll>>brr(8,vector<ll>(7));

pll split(ll x){
    return {x/7,x%7};
}

ll ans(ll x){
    while(x<56&&vis[x])x++;
    if(x>=56){
//        for(auto k:brr){
//            for(auto kk:k)cout<<setw(3)<<kk;cout<<'\n';
//        }
        return 1;
    }
    auto [a,b]=split(x);
    ll an=0;
    if(x<49){
        auto [na,nb]= pll({a+1,b});
        set<ll>st={arr[a][b],arr[na][nb]};
        if(!vis[x+7]&&pos.find(st)!=pos.end()){
            pos.erase(st);
            vis[x]=vis[x+7]=1;
            brr[a][b]=brr[na][nb]= std::find(vct.begin(), vct.end(),st)-vct.begin();
            an+=ans(x+1);
            pos.insert(st);
            vis[x]=vis[x+7]=0;
        }
    }
    if(b<6){
        auto [na,nb]= pll({a,b+1});
        set<ll>st={arr[a][b],arr[na][nb]};
        if(!vis[x+1]&&pos.find(st)!=pos.end()){
            pos.erase(st);
            vis[x]=vis[x+1]=1;
            brr[a][b]=brr[na][nb]= std::find(vct.begin(), vct.end(),st)-vct.begin();
            an+=ans(x+1);
            pos.insert(st);
            vis[x]=vis[x+1]=0;
        }
    }
    return an;
}

void solve(ll testcase){
    ll i,j,k;
    ll n;
    for(i=0;i<=6;i++){
        for(j=i;j<=6;j++){
            pos.insert({i,j});
            vct.push_back({i,j});
        }
    }
    for(i=0;i<8;i++){
        for(j=0;j<7;j++){
            char x;
            cin>>x;
            arr[i][j]=x-'0';
        }
    }
    cout<<ans(0);
}

int main(){
    setup();
    preprocess();
    ll t=1;
//    cin>>t;
    for(ll i=0;i<t;i++){
        solve(i+1);
    }
}