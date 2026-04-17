#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;
#ifdef kidw0124
    constexpr bool xdebug = true;
#else
    constexpr bool xdebug = false;
#endif
#define debug if constexpr (xdebug) cout<<"[DEBUG] "
void setup(){
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
#endif
}

void preprocess(){
    ll i,j,k;


}

void solve(ll testcase){
    ll i,j,k;
    ll n=1,w=1;
    vector<pll>arr;
    while(cin>>n>>w,n&&w){
        arr.emplace_back(n,w);
    }
    vector<pll>brr;
    for(i=1;i<=200;i++){
        for(j=i+1;j<=200;j++){
            brr.emplace_back(i,j);
        }
    }
    sort(brr.begin(), brr.end(),[](auto&l,auto&r){
       return l.first*l.first+l.second*l.second==r.first*r.first+r.second*r.second?
                l.second>r.second:
                l.first*l.first+l.second*l.second<r.first*r.first+r.second*r.second;
    });
    for(auto [a,b]:brr){
        debug<<a<<' '<<b<<'\n';
    }
    for(auto [a,b]:arr){
        auto d=(find(brr.begin(),brr.end(),pll({a,b}))+1);
        cout<<d->first<<' '<<d->second<<'\n';
    }
}


int main(){
    setup();
    preprocess();
    ll t=1;
//    cin>>t;
    for(ll tc=1;tc<=t;tc++){
        solve(tc);
    }
}