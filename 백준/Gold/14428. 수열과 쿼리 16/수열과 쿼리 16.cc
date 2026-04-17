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
const ll mn=100000+5;
ll arr[mn]={INT_MAX};
ll segtree[4*mn]={INT_MAX};
bool cmp(ll a, ll b){
    if(a==1e18)return false;
    else if(b==1e18)return true;
    return arr[a]==arr[b]?a<b:arr[a]<arr[b];
}
ll update(ll st, ll en, ll node, ll index){
    if(index<st||index>en){
        return segtree[node];
    }
    else if(st==en){
        return segtree[node]=st;
    }
    else{
        ll x[3]={update(st,(st+en)/2,node<<1,index),update((st+en)/2+1,en,(node<<1)|1,index),segtree[node]};
        sort(x,x+3, cmp);
        return segtree[node]=x[0];
    }
}

ll get(ll st, ll en, ll node, ll l, ll r){
    if(r<st||l>en){
        return 0;
    }
    else if(st==en){
        return segtree[node];
    }
    else if(l<=st&&en<=r){
        return segtree[node];
    }
    else{
        ll x[2]={get(st,(st+en)/2,node<<1,l,r),get((st+en)/2+1,en,(node<<1)|1,l,r)};
        sort(x,x+2, cmp);
        return x[0];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    //freopen("input.txt","r",stdin);
    cin>>n;
    for(i=0;i<n+1;i++)arr[i]=1e18;
    for(i=0;i<4*n+1;i++)segtree[i]=1e18;
    for(i=1;i<=n;i++){
        cin>>arr[i];
        update(1,n,1,i);
    }
    cin>>m;
    for(i=0;i<m;i++){
        ll a,b,c;
        cin>>a;
        if(a==1){
            cin>>a>>b;
            arr[a]=b;
            update(1,n,1,a);
        }
        else{
            cin>>a>>b;
            cout<<get(1,n,1,a,b)<<'\n';
        }
    }
    return 0;
}
