#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

struct Q{
    ll p,q;
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

void solve() {
    ll i,j;
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(auto&x:arr)cin>>x;
    auto cht=[&n](const vector<ll>arr)->vector<ll>{
        LI_CHAO cht;
        vector<ll>dp(n);
        dp[0]=0;
        cht.update(0,{arr[0],0});
        for(int i=1;i<n;i++){
            dp[i]=cht.query_max(0,i);
            cht.update(0,{arr[i],-i*arr[i]});
        }
        return dp;
    };
    vector<ll>t1=cht(arr);
    reverse(arr.begin(),arr.end());
    vector<ll>t2=cht(arr);
    reverse(t2.begin(),t2.end());
    ll ans=1e18;
    for(int i=0;i<n;i++){
        ans=min(ans,max(t1[i],t2[i]));
    }
    cout<<ans<<'\n';


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
    preprocess();
    ll t=1;
//    cin>>t;
    while(t--)solve();
#ifdef kidw0124
    cout<<clock()-beg<<"ms\n";
#endif
}
