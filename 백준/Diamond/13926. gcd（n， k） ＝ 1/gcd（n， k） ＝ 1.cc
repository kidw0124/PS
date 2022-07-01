#include<bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
typedef __int128_t ll;
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
ll func(ll x, ll c, ll mod){
    return ((__int128_t)x*x%mod+c)%mod;
}

ll rho(ll n, ll x_0, ll c){
    ll x=x_0;
    ll y=x_0;
    do{
        x=func(x,c,n);
        y=func(y,c,n);
        y=func(y,c,n);
    }while((!x)||(!y)||gcd(abs(x-y),n)==1);
    return gcd(abs(x-y),n);
}

LL n;

map<ll,int>primes;

bool checkComp(ll n, ll a, ll d, ll s) {
    ll x = POW(a, d, n);
    if(x==1||x==n-1)return false;
    for(ll i=0;i<s;i++){
        x=(__int128_t)x*x%n;
        if(x==n-1)return false;
    }
    return true;
}

bool isPrime(ll n){
    if(n<2)return false;
    int r=0;
    ll d=n-1;
    while(!(d&1)){
        d>>=1;
        r++;
    }
    for(ll a:{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}) {
        if(n==a)return true;
        if(checkComp(n,a,d,r))return false;
    }
    return true;
}

void factorize(ll n){
    if(n==1)return;
    if(isPrime(n)){
        if(primes.find(n)!=primes.end()){
            primes[n]++;
        }
        else{
            primes[n]=1;
        }
        return;
    }
    for(ll a:{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}) {
        if(n%a==0){
            if(primes.find(a)!=primes.end()){
                primes[a]++;
            }
            else{
                primes[a]=1;
            }
            factorize(n/a);
            return;
        }
    }
    ll g=1;
    while((g=rho(n,rand()%(n-2)+2,rand()%10+1))==1);
    factorize(g);
    factorize(n/g);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    factorize(n);
    ll ans=1;
    for(auto i:primes){
        ll x=1;
        while(--i.second){
            x*=i.first;
        }
        ans*=x*i.first-x;
    }
    cout<<(LL)ans;
    return 0;
}
