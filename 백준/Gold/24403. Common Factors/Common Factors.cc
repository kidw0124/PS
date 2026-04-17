#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem=1ull<<63-1){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
ll n;
const ll maxn=1e6;
vector<ll>primes;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    ll ans1=1,ans2=1;
    bitset<maxn+2>isprime;
    for(i=2;;i++){
        if(isprime[i])continue;
        else if((__int128_t)ans1*i<=(__int128_t)n){
            ans1*=i;
            ans2*=i-1;
            for(j=i*i;j<=maxn+1;j+=i){
                isprime[j]=1;
            }
        }
        else break;
    }
    cout<<(ans1-ans2)/gcd(ans1,ans2)<<'/'<<ans1/gcd(ans1,ans2);
    return 0;
}
