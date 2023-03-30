#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t LL;
typedef __uint128_t ULL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto& x: a)
#define endl '\n'

#define debug if constexpr (xdebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (xdebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugc(c) if constexpr (xdebug) { cout << "[DEBUG] "<< #c << ": "; for (const auto& elem : c) cout << elem << ", "; cout << '\n'; }

#ifndef ONLINE_JUDGE
constexpr bool xdebug = true;
#else
constexpr bool xdebug = false;
#endif
void setup(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll powm(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)%rem)if(b&1)p=(p*a)%rem;return p;}
pair<ll, ll> extended_gcd(ll a, ll b) {
    if (b == 0) return { 1, 0 };
    auto t = extended_gcd(b, a % b);
    return { t.second, t.first - t.second * (a / b) };
}
// find x in [0,m) s.t. ax === gcd(a, m) (mod m)
ll modinverse(ll a, ll m) {
    return (extended_gcd(a, m).first % m + m) % m;
}


ll mod=998244353;

void solve(){
    ll i,j;
    ll n;
    cin>>n;
    vector<vector<ll>>edge(n+1);
    vector<ll>par(n+1);
    for(i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    queue<ll>que({1});
    while (!que.empty()){
        ll now=que.front();
        que.pop();
        for(auto k:edge[now]){
            if(!par[k]&&k>1)que.push(k),par[k]=now;
        }
    }
    for(auto k:par){
        if(k)cout<<k<<'\n';
    }
}

int main() {
    setup();
    ll t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}
