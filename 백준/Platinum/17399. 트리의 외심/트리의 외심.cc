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
ll POW(ll a, ll b, ll rem=1ull<<63-1){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
ll n;
vector<vector<ll>>arr;
vector<ll>depth;
vector<vector<ll>>anc;

int lca(ll x, ll y){
    if(depth[x]<depth[y])swap(x,y);
    ll d=depth[x]-depth[y];
    ll i=0;
    while(d){
        if(d&1){
            x=anc[x][i];
        }
        d>>=1;
        i++;
    }
    if(x==y){
        return x;
    }
    else{
        while(anc[x][0]!=anc[y][0]){
            int i=1;
            while(anc[x].size()>i&&anc[y].size()>i&&anc[x][i]!=anc[y][i])i++;
            x=anc[x][i-1],y=anc[y][i-1];
        }
        return anc[x][0];
    }
}

int dist(ll x, ll y){
    ll l=lca(x,y);
    return depth[x]+depth[y]-2*depth[l];
}
int mid(ll x, ll y,ll d){
    if(depth[x]<depth[y])swap(x,y);
    d>>=1;
    ll i=0;
    while(d){
        if(d&1){
            x=anc[x][i];
        }
        d>>=1;
        i++;
    }
    return x;
}

int ans(ll x, ll y, ll z){
    ll d=dist(x,y);
    if(d&1){
        return -1;
    }
    ll p=mid(x,y,d);
    if(dist(p,z)==d>>1){
        return p;
    }
    d=dist(y,z);
    if(d&1){
        return -1;
    }
    p=mid(y,z,d);
    if(dist(p,x)==d>>1){
        return p;
    }
    d=dist(x,z);
    if(d&1){
        return -1;
    }
    p=mid(x,z,d);
    if(dist(p,y)==d>>1){
        return p;
    }
    else return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    arr.resize(n+1);
    depth.resize(n+1);
    anc.resize(n+1);
    for(i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    stack<ll> stk;
    stk.push(1);
    depth[1]=1;
    while(!stk.empty()){
        ll now=stk.top();
        stk.pop();
        for(auto k:arr[now]){
            if(depth[k]){
                continue;
            }
            else{
                depth[k]=depth[now]+1;
                anc[k].push_back(now);
                ll t=now;
                i=0;
                for(i=0;anc[anc[k][i]].size()>i;i++){
                    anc[k].push_back(anc[anc[k][i]][i]);
                }
                stk.push(k);
            }
        }
    }
    ll q;
    cin>>q;
    for(i=0;i<q;i++){
        ll a, b, c;
        cin>>a>>b>>c;
        cout<<ans(a,b,c)<<'\n';
    }
    return 0;
}
