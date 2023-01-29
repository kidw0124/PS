//
// Created by kidw0 on 2022-12-31.
//
#include<bits/stdc++.h>
using namespace std;
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
ll mod=1e9+7;
int main() {
    setup();
    ll i,j;
    ll n;
    ll k;
    cin>>n>>k;
    if(n>=k){
        cout<<(powm(2,k,mod)+mod-1)%mod;
        return 0;
    }
    vector<ll>facto(k+1),inv(k+1),ncr(k/2+1);
    facto[0]=1;
    for(i=1;i<=k;i++){
        facto[i]=facto[i-1]*i;
        facto[i]%=mod;
    }
    inv[k]=powm(facto[k],mod-2,mod);
    for(i=k-1;i>=0;i--){
        inv[i]=inv[i+1]*(i+1);
        inv[i]%=mod;
    }
    ll ans=0;
    for(i=0;i<=min(n,k/2);i++){
        ncr[i]=(facto[k]*inv[i])%mod*inv[k-i]%mod;
    }
    for(i=1;i<=min(k,n);i++){
        if(i<=k/2)ans+=ncr[i];
        else ans+=ncr[k-i];
        ans%=mod;
    }
    cout<<ans;
    return 0;
}