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
typedef long double ld;
typedef __float128 LD;
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
ll mod=1'000;//'000'007;
LD eps=1e-12;

vector<vector<ll>> operator*(const vector<vector<ll>>&l, const vector<vector<ll>>& r){
    vector<vector<ll>> ret(l.size(),vector<ll>(r[0].size()));
    ll i,j,k;
    for(i=0;i<l.size();i++){
        for(j=0;j<l.size();j++){
            for(k=0;k<l.size();k++){
                ret[i][j]+=l[i][k]*r[k][j];
                ret[i][j]%=mod;
            }
        }
    }
    return ret;
}

vector<vector<ll>> operator^(const vector<vector<ll>>&l, const ll&r){
    vector<vector<ll>>ret(l.size(),vector<ll>(l.size()));
    if(r==0){
        for(ll i=0;i<l.size();i++){
            ret[i][i]=1;
        }
        return ret;
    }
    else if(r==1){
        return l;
    }
    else{
        ret = l^(r/2);
        ret=ret*ret;
        if(r&1)ret=ret*l;
    }
    return ret;
}

void solve(){
    ll i,j;
    ll t;
    cin>>t;
    ll test=1;
    while(t--){
        ll n;
        cin>>n;
        vector<vector<ll>>arr(2, vector<ll>(2));
        arr={{6,mod-4},{1,0}};
        arr=arr^(n-1);
        cout<<"Case #"<<test<<": "<<setw(3)<<setfill('0')<<(6*arr[0][0]+2*arr[0][1]+999)%mod<<'\n';
        test++;
    }
}

int main() {
    setup();
    solve();
    return 0;
}
