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
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll powm(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)%rem)if(b&1)p=(p*a)%rem;return p;}

bitset<1000005>primes;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll i,j;
    ll n;
    cin>>n;
    vector<ll>arr(n),pfs(n+1);
    ll ans=0;
    primes.set();
    primes[0]=primes[1]=0;
    for(i=2;i<1000005;i++){
        if(primes[i]){
            for(j=i*i;j<1000005;j+=i)primes[j]=0;
        }
    }
    for(i=0;i<n;i++){
        cin>>arr[i];
        pfs[i+1]=pfs[i]+arr[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(primes[j-i+1])if(primes[pfs[j+1]-pfs[i]])ans++;
        }
    }
    cout<<ans;

    return 0;
}
