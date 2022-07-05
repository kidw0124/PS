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

vector<ll>par_red,par_blue;
ll _find(ll x,vector<ll>&par){
    if(par[x]!=x){
        return _find(par[x],par);
    }
    return x;
}

void _union(ll x,ll y, vector<ll>&par){
    x=_find(x,par);
    y=_find(y,par);
    if(x!=y)par[y]=_find(x,par);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n,m,k;
    while(1){
        cin>>n>>m>>k;
        if(!n)return 0;
        par_red.clear(),par_blue.clear();
        par_red.resize(n+1),par_blue.resize(n+1);
        iota(all(par_red),0);
        iota(all(par_blue),0);
        for(i=0;i<m;i++){
            char t;
            ll x,y;
            cin>>t>>x>>y;
            if(t=='R'){
                _union(x,y,par_red);
            }
            else if(t=='B'){
                _union(x,y,par_blue);
            }
        }
        set<ll>r,b;
        for(i=1;i<=n;i++){
            par_red[i]=_find(i,par_red);
            par_blue[i]=_find(i,par_blue);
        }
        for(auto i:par_red)r.insert(i);
        for(auto i:par_blue)b.insert(i);
        ll mm=r.size()-1-1,M=n-b.size()+1;
        if(mm<=k&&k<=M)cout<<"1\n";
        else cout<<"0\n";
    }


    return 0;
}
