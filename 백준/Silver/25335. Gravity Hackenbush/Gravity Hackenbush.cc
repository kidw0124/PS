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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n,m,r=0,g=0,b=0;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>j>>j;
    }
    for(i=0;i<m;i++){
        char x;
        cin>>j>>j>>x;
        if(x=='R')r++;
        if(x=='G')g++;
        if(x=='B')b++;
    }
    r+=g-g/2;
    b+=g/2;
    if(r<=b)cout<<"jhnan917";
    else cout<<"jhnah917";


    return 0;
}
