#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#ifdef DWOO
constexpr bool XDEBUG = true;
#else
constexpr bool XDEBUG = false;
#endif
#define all(x) (x).begin(), (x).end()


void setup(){
    if(XDEBUG){
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
    else{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void preprocess(){
    ll i,j,k;
}

struct LI_CHAO{
    struct Line{
        ll a,b;
        ll f(ll x){
            return a*x+b;
        }
        Line(ll a, ll b):a(a),b(b){}
    };
    struct Node{
        ll l=-1,r=-1,s,e;
        Line x;
        Node(ll s, ll e, Line x):s(s),e(e),x(x){}
    };

    vector<Node>tree;

    LI_CHAO(){
        tree.push_back(Node(-2e12,2e12,Line(0,-2e18)));
    }

    void update(ll n, Line k){
        ll st=tree[n].s,en=tree[n].e;
        Line lo=tree[n].x,hi=k;
        ll mid=(st+en)>>1;
        if(lo.f(st)>hi.f(st))swap(lo,hi);
        if(lo.f(en)<=hi.f(en)){
            tree[n].x=hi;
        }
        else{
            if(lo.f(mid)<hi.f(mid)){
                tree[n].x=hi;
                if(tree[n].r==-1){
                    tree[n].r=tree.size();
                    tree.push_back(Node(mid+1,en,Line(0,-2e18)));
                }
                update(tree[n].r,lo);
            }
            else{
                tree[n].x=lo;
                if(tree[n].l==-1){
                    tree[n].l=tree.size();
                    tree.push_back(Node(st,mid,Line(0,-2e18)));
                }
                update(tree[n].l,hi);
            }
        }
    }
    ll query_min(ll n, ll x){
        if(n==-1)return 2e18;
        ll st=tree[n].s,en=tree[n].e;
        ll mid=(st+en)>>1;
        if(x<=mid){
            return min(tree[n].x.f(x), query_min(tree[n].l,x));
        }
        else{
            return min(tree[n].x.f(x), query_min(tree[n].r,x));
        }
    }
    ll query_max(ll n, ll x){
        if(n==-1)return -2e18;
        ll st=tree[n].s,en=tree[n].e;
        ll mid=(st+en)>>1;
        if(x<=mid){
            return max(tree[n].x.f(x), query_max(tree[n].l,x));
        }
        else{
            return max(tree[n].x.f(x), query_max(tree[n].r,x));
        }
    }
};

void solve(ll testcase){
    ll i,j,k;
//    cout<<"Case #"<<testcase<<'\n';
//    ll n;
//    cin>>n;
//    vector<ll>arr(2*n);
//    vector<ll>brr(n-1);
//    ll ans=0;
//    for(i=0;i<n;i++){
//        cin>>arr[i<<1]>>arr[i<<1|1];
//        if(i){
//            brr[i-1]=arr[i<<1]-arr[(i-1)<<1|1];
//        }
//    }
//    ll m;
//    cin>>m;
//    vector<ll>p(m),w(m);
//    LI_CHAO tree;
//    for(i=0;i<m;i++)cin>>p[i];
//    for(i=0;i<m;i++)cin>>w[i];
//    for(i=0;i<m;i++){
//        tree.update(0,{p[i],w[i]});
//    }
//    for(i=0;i<n-1;i++){
//        ans+=tree.query(0,brr[i]);
//    }
//    for(i=0;i<n;i++){
//        ans+=(arr[i<<1|1]-arr[i<<1])*p[0];
//    }
//    cout<<ans<<'\n';
    LI_CHAO tree;
    ll n;
    cin>>n;
    for(i=0;i<n;i++){
        ll a,b,c;
        cin>>a>>b;
        if(a==1){
            cin>>c;
            tree.update(0,{b,c});
        }
        else{
            cout<<tree.query_max(0,b)<<'\n';
        }
    }
}

int main(){
    setup();
    preprocess();
    ll t=1;
//    cin>>t;
    for(ll i=0;i<t;i++){
        solve(i+1);
    }
}