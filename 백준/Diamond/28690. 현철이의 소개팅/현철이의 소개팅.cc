#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//gp_hash_table<int, int> table;
using namespace __gnu_pbds;
using ll = long long;
using LL = __int128;
using pll = pair<ll, ll>;
using ld = long double;

struct Q{
    LL p,q;
    void reduce(){
        if(!p||!q)return;
        ll g = gcd(p,q);
        p/=g;
        q/=g;
    }
    bool operator<(const Q& o)const{
        return p*o.q<q*o.p;
    }
};

void preprocess() {

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
        tree.push_back(Node(-2e9,2e9,Line(0,-2e18)));
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

void solve() {
    ll i,j;
    ll n,c;
    cin>>n>>c;
    vector<ll>arr(n+1),sumsq(n+1),sum(n+1);
    for(i=0;i<n;i++)cin>>arr[i+1];
    vector<ll>dp(n+1,0);
    LI_CHAO lct;
    for(i=1;i<=n;i++){
        sum[i]=sum[i-1]+arr[i];
        sumsq[i]=sumsq[i-1]+arr[i]*arr[i];
    }
    lct.update(0,{0,-2*c});
    for(i=1;i<=n;i++){
        dp[i]=-lct.query_max(0,sum[i])+sum[i]*sum[i];
        lct.update(0,{2*sum[i],-(dp[i]+sum[i]*sum[i]+2*c)});
    }
    cout<<(sumsq[n]+dp[n]-2*c)/2%(ll)(1e9+7)<<'\n';
}

int main() {
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    clock_t beg = clock();
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
//    preprocess();
    ll t=1;
//    cin>>t;
    while(t--)solve();
#ifdef kidw0124
    cout<<clock()-beg<<"ms\n";
#endif
}
