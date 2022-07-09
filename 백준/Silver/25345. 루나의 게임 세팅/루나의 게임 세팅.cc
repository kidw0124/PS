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

ll combination(ll, ll, ll=1'000'000'007);
ll inv(ll, ll);
ll pow(ll, ll, ll);
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n,k;
    cin>>n>>k;
    cout<<combination(n,k)*POW(2,k-1,1e9+7)%(ll)(1e9+7);


    return 0;
}

ll combination(ll n, ll k, ll mod){
    ll res=1;
    for(ll i=1;i<=k;i++){
        res=(res*(n-i+1))%mod;
        res=(res*inv(i,mod))%mod;
    }
    return res;
}

ll inv(ll a, ll mod = 1000000007){
    return pow(a,mod-2,mod);
}

ll pow(ll a, ll b, ll mod = 1000000007){
    ll res=1;
    while(b){
        if(b&1) res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
