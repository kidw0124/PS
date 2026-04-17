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
ll n, m, k, treesize=4000000;
const ll mod=1e9+7;
vl arr;
vector<ll> segtree(treesize,0);

ll make_segtree(ll st, ll en, ll node){
    if(st==en){
        return segtree[node]=arr[st];
    }
    else{
        return segtree[node]=make_segtree(st, (st+en)/2, node<<1) * make_segtree((st+en)/2 + 1, en, (node<<1) + 1) % mod;
    }
}

ll calc_sum(ll st, ll en,ll node, ll l, ll r){
    if(l>en||r<st)return 1;
    else if(l<=st&&en<=r) return segtree[node];
    else{
        return calc_sum(st, (st+en)/2, node<<1, l, r) * calc_sum((st+en)/2 + 1, en, (node<<1) + 1, l, r) % mod;
    }
}

ll update(ll st, ll en, ll node, ll index, ll val){
    if(st==en){
        return segtree[node]=arr[st];
    }
    if(index<st||index>en){
        return segtree[node];
    }
    else{
        return segtree[node]=update(st, (st+en)/2, node<<1, index, val)*update((st+en)/2 + 1, en, (node<<1) + 1, index, val) % mod;
    }
}

ll a, b, c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>m>>k;
    treesize=1ll<<(65-__builtin_clz(n));
    arr=*(new vl(n));
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    make_segtree(0,n-1,1);
//    for(j=0;j<treesize;j++){
//        cout<<(ll)segtree[j]<<' ';
//    }
    //    cout<<'\n';
    for(i=0;i<m+k;i++){
        cin>>a>>b>>c;
        if(a==1){
            arr[b-1]=c;
            update(0,n-1,1,b-1,c);
        }
        else{
                cout<<(ll)calc_sum(0,n-1,1,b-1,c-1)<<'\n';
        }
    }
    return 0;
}
