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
ll n,m;
ll n2,n5,m2,m5,nn2,nn5;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll ans=0;
    cin>>n>>m;
    ll nn=n-m;
    ll t=n;
    while(n){
        n5+=n/5;
        n/=5;
    }
    n=t;
    while(n){
        n2+=n/2;
        n/=2;
    }
    t=nn;
    while(nn){
        nn5+=nn/5;
        nn/=5;
    }
    nn=t;
    while(nn){
        nn2+=nn/2;
        nn/=2;
    }
    t=m;
    while(m){
        m5+=m/5;
        m/=5;
    }
    m=t;
    while(m){
        m2+=m/2;
        m/=2;
    }
    ans=min(n2-nn2-m2,n5-m5-nn5);
    cout<<ans;
    return 0;
}
