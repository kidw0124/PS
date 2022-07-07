#include<bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
map<pll,ll>mp;
ll ans(ll s,ll e){
    ll ret=0;
    if(!s&&!e)return 0;
    if(mp.find({s,e})!=mp.end())return mp[{s,e}];
    for(ll i=1;i<32;i++){
        ll m=max(s,(1ll<<i)-1),M=min(e,(2ll<<i)-2);
        if(m<=M)ret=max(ret,ans(m-((1<<i)-1),M-((1<<i)-1))+i);
    }
    return mp[{s,e}]=ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll t;
    cin>>t;
    while(t--){
        ll s,e;
        cin>>s>>e;
        cout<<ans(s,e)<<'\n';
    }

    return 0;
}
