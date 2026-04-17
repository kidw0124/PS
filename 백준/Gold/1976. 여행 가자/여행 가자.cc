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
vector<ll> par;

ll _find(ll t){
    if(par[t]==t)return t;
    else return par[t]=_find(par[t]);
}

void _union(ll a, ll b){
    a=_find(a);
    b=_find(b);
    par[b]=a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>m;
    par.resize(n+1);
    iota(par.begin(),par.end(),0);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ll k;
            cin>>k;
            if(k)_union(i+1,j+1);
        }
    }
    cin>>j;
    ll p=_find(j);
    for(i=1;i<m;i++){
        cin>>j;
        if(p!=_find(j)){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
