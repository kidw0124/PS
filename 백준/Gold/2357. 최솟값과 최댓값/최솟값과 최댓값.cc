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
ll n, m, k, treesize;
vl arr;
vector<pll> segtree;

pll make_segtree(ll st, ll en, ll node){
    if(st==en){
        return segtree[node]={arr[st],arr[st]};
    }
    else{
        pll a=make_segtree(st, (st+en)/2, node<<1),b=make_segtree((st+en)/2 + 1, en, (node<<1) + 1);
        return segtree[node]={min(a.first,b.first),max(a.second,b.second)};
    }
}

pll calc_sum(ll st, ll en,ll node, ll l, ll r){
    if(l>en||r<st)return {INT_MAX,INT_MIN};
    else if(l<=st&&en<=r) return segtree[node];
    else{
        pll a=calc_sum(st, (st+en)/2, node<<1,l,r),b=calc_sum((st+en)/2 + 1, en, (node<<1) + 1,l,r);
        return {min(a.first,b.first),max(a.second,b.second)};
    }
}

ll a, b, c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>m;
    treesize=1<<(65-__builtin_clz(n));
    arr=*(new vl(n));
    segtree = *(new vector<pll>(treesize,{0,0}));
    for(i=0;i<n;i++)cin>>arr[i];
    make_segtree(0,n-1,1);
//    for(i=0;i<treesize;i++){
//        cout<<(ll)segtree[i]<<' ';
//    }
    for(i=0;i<m;i++){
        cin>>a>>b;
        pll x=calc_sum(0,n-1,1,a-1,b-1);
        cout<<x.first<<' '<<x.second<<'\n';
    }
    return 0;
}
