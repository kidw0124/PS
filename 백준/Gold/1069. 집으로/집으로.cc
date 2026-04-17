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
long double x,y;
ll d,t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>x>>y>>d>>t;
    long double k=sqrt(x*x+y*y);
    if(d<=t){
        cout<<fixed<<setprecision(111)<<k;
        return 0;
    }
    long double ans=floor(k/d)*t,ans2=ceil(k/d)*t,ans3=max(ceil(k/d),(long double)2.0)*t;
    ans+=k-floor(k/d)*d,ans2+=ceil(k/d)*d-k;
    cout<<fixed<<setprecision(111)<<min({ans,ans2,ans3});
    return 0;
}
