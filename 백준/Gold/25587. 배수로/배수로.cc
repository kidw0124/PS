#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "

void setup(){
    if(ddebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    else {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void preprocess() {
    ll i, j;


}

ld eps=1e-12;

void solve(ll testcase){
    ll i,j;
    ll n,m;
    cin>>n>>m;
    vector<ll>arr(n),brr(n);
    for(auto&k:arr)cin>>k;
    for(auto&k:brr)cin>>k;
    vector<ll>grp(n),sz(n,1);
    ll ans=0;
    iota(grp.begin(), grp.end(),0);
    function<ll(ll)> _find=[&](ll x){
        if(x==grp[x])return x;
        else return grp[x]=_find(grp[x]);
    };
    auto _grp=[&](ll x, ll y){
        sz[x]+=sz[y];
        arr[x]+=arr[y];
        brr[x]+=brr[y];
        grp[y]=x;
    };
    for(i=0;i<n;i++){
        if(arr[i]<brr[i])ans++;
    }
    for(i=0;i<m;i++){
        ll q;
        cin>>q;
        if(q==1){
            ll x,y;
            cin>>x>>y;
            x--,y--;
            x=_find(x);
            y=_find(y);
            if(x==y)continue;
            if(arr[x]<brr[x])ans-=sz[x];
            if(arr[y]<brr[y])ans-=sz[y];
            _grp(x,y);
            if(arr[x]<brr[x])ans+=sz[x];
        }
        else{
            cout<<ans<<'\n';
        }
    }
}

int main(){
    setup();
    preprocess();
    ll t = 1;
//    cin >> t;
    for (ll testcase = 1; testcase <= t; testcase++) {
        solve(testcase);
    }
    return 0;
}
