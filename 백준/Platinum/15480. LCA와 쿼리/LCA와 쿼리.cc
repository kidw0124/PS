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
vl dep(100000+1,-1);
vector<vl> graph(100000+1);
vector<vl> anc(100000+1);

void calc_dep(ll node, ll par){
    anc[node].pb(par);
    for(ll i=1;(1ll<<i)<=dep[node];i++){
        anc[node].pb(anc[anc[node][i-1]][i-1]);
    }
    for(ll i:graph[node]){
        if(dep[i]==-1){
            dep[i]=dep[node]+1;
            calc_dep(i,node);
        }
    }
}
ll calc_lca(ll a, ll b){
    if(dep[a]>dep[b])swap(a,b);
    if(dep[a]!=dep[b]){
        ll diff=dep[b]-dep[a];
        for(ll i=0;diff;i++){
            if(diff&1){
                b=anc[b][i];
            }
            diff>>=1;
        }
    }
    while(a^b){
        ll i;
        for(i=anc[a].size()-1;i>=0;i--){
            if(anc[a][i]^anc[b][i]){
                a=anc[a][i];
                b=anc[b][i];
                break;
            }
        }
        if(i==-1){
            a=anc[a][0];
            break;
        }
    }
    return a;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    for(i=0;i<n-1;i++){
        ll t,p;
        cin>>t>>p;
        graph[t].pb(p);
        graph[p].pb(t);
    }
    dep[1]=1;
    calc_dep(1,0);
    cin>>m;
    while(m--){
        ll r,t,p;
        cin>>r>>t>>p;
        ll a=calc_lca(r,t);
        ll b=calc_lca(r,p);
        ll c=calc_lca(t,p);
        if(dep[a]<dep[b])a=b;
        if(dep[a]<dep[c])a=c;
        cout<<a<<'\n';
    }
    return 0;
}
