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
ll f[1000004];
ll InverseEuler(ll n, ll MOD)
{
 return POW(n,MOD-2,MOD);
}

ll C(ll n, ll r, ll MOD)
{

 return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    f[0]=1;
    for(i=1;i<1000004;i++){
        f[i]=f[i-1]*i;
        f[i]%=(ll)1e9+7;
    }
    cin>>i>>j;
    cout<<C(i,j,(ll)1e9+7);


    return 0;
}
