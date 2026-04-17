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
ll n,q;

vector<ll> color;
vector<ll> oripar,par;
vector<pair<ll,ll>>query;
vector<set<ll>>inc;

ll _find(ll a){
    if(a==par[a])return a;
    else return par[a]=_find(par[a]);
}

void _union(ll a, ll b){
    a=_find(a);
    b=_find(b);
    if(inc[a].size()<inc[b].size())swap(a,b);
    for(auto k:inc[b]){
        inc[a].insert(k);
    }
    inc[b].clear();
    par[b]=a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>q;
    oripar.resize(n+1);
    color.resize(n+1);
    inc.resize(n+1);
    oripar[1]=1;
    for(i=2;i<=n;i++){
        cin>>oripar[i];
    }
    for(i=1;i<=n;i++){
        cin>>color[i];
        inc[i].insert(color[i]);
    }
    par=*new vector<ll>(oripar);
    for(i=0;i<q+n-1;i++){
        ll a,b;
        cin>>a>>b;
        query.push_back({a,b});
        if(a==1){
            par[b]=b;
        }
    }
    for(i=2;i<=n;i++){
        if(par[i]!=i){
            _union(i,par[i]);
        }
    }
    stack<ll> st;
    for(i=n-1+q-1;i>=0;i--){
        if(query[i].first==1){
            _union(query[i].second,oripar[query[i].second]);
        }
        else{
            query[i].second=_find(query[i].second);
            st.push(inc[query[i].second].size());
        }
    }
    while(!st.empty()){
        cout<<st.top()<<'\n';
        st.pop();
    }
    return 0;
}
