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
bool prime[1000005];
map<ll,ll> primes;
ll n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    if(n==1){
        cout<<1;
        return 0;
    }
    for(i=2;i*i<=n;i++){
        if(!prime[i]){
            primes[i]=0;
            for(j=i;(j*i)<=sqrt(n+1);j++){
                prime[j*i]=true;
            }
        }
    }
    for(auto i:primes){
        while(!(n%i.first))primes[i.first]++,n/=i.first;
    }
    ll ans=1;
    if(n-1)primes[n]=1;
    for(auto i:primes){
        if(i.second){
            ll aaa=1;
            for(j=1;j<i.second;j++){
                aaa*=i.first;
            }
            ans*=aaa*(i.first-1);
        }
    }
    cout<<ans;

    return 0;
}
