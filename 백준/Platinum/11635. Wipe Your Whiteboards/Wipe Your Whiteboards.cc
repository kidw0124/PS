#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma gcc optimize("O3,unroll-loops")
#pragma gcc target("avx,avx2,fma")
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pll = pair<ll,ll>;

constexpr ll MOD = 1e9+7;
constexpr ll MOD_2=500'000'004;
constexpr ll MOD_4=250'000'002;
constexpr ll MOD_8=125'000'001;

void preprocess(){

}

tuple<ll,ll,ll>ext_gcd(ll a, ll b){
    if(!b)return{a,a>0?1:-1,0};
    else{
        auto [g,x,y]=ext_gcd(b,a%b);
        return {g,y,x-a/b*y};
    }
}

void solve() {
    ll i,j,k;
    ll r,s,q;
    cin>>r>>s>>q;
    auto [g,x,y]=ext_gcd(r,s);
    g=abs(g);
    q/=g,r/=g,s/=g;
    x*=q;
    y*=q;
    s=-s;
    if(x<=0){
        k=x/s;
        x-=k*s;
        y-=k*r;
        if(x<=0){
            x+=s;
            y+=r;
        }
        if(x<=0){
            x+=s;
            y+=r;
        }
    }
    if(y<=0){
        k=y/r;
        x-=k*s;
        y-=k*r;
        if(y<=0){
            x+=s;
            y+=r;
        }
        if(y<=0){
            x+=s;
            y+=r;
        }
    }
    k=min((x-1)/s,(y-1)/r);
    x-=k*s;
    y-=k*r;
    cout<<x<<" "<<y<<"\n";







}

int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
}
