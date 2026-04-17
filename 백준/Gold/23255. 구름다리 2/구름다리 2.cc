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
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
ll n,m;
    vl par;

ll _find(ll x){
    if(par[x]==x)return x;
    else return par[x]=_find(par[x]);
}

void _union(ll x, ll y){
    par[_find(y)]=_find(x);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>m;
    par.resize(n+1);
    iota(par.begin(),par.end(),0);
    vector<set<ll>>brr(n+1);
    for(i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        brr[a].insert(b);
        brr[b].insert(a);
    }
    vl crr(n+1);
    for(i=1;i<=n;i++){
        set<ll> drr;
        for(auto k:brr[i]){
            if(k>i)break;
            else drr.insert(crr[k]);
        }
        ll t=1;
        for(auto x:drr){
            if(t!=x){
                break;
            }
            else t++;
        }
                crr[i]=t;
        cout<<crr[i]<<' ';
    }
    return 0;
}
