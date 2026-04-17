#include<bits/stdc++.h>
using namespace std;
#ifdef ATCODER
#include<atcoder/all>
using namespace atcoder;
#endif
using ll = long long;
using pll = pair<ll,ll>;
using tlll = tuple<ll,ll,ll>;
using tllll = tuple<ll,ll,ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto &x : a)
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "

#ifndef kidw0124
const ll TSIZE = 1 << 20; // always 2^k form && n <= TSIZE
#else
const ll TSIZE = 1 << 3; // always 2^k form && n <= TSIZE
#endif

void yes(){
    cout<<"Yes\n";
}

void no(){
    cout<<"No\n";
}

constexpr ll mod=1e9+7;
vector<ll>part;
void preprocess(){
    part.resize(3e5+1);
    part[0]=1;
    for(ll i=1;i<part.size();i++){
        // partition number with pentagonal number
        ll j=1;
        while(1){
            ll p1=(j*(3*j-1))/2;
            ll p2=(j*(3*j+1))/2;
            if(p1>i && p2>i)break;
            if(p1<=i){
                if(j&1)part[i]+=part[i-p1];
                else part[i]-=part[i-p1];
            }
            if(p2<=i){
                if(j&1)part[i]+=part[i-p2];
                else part[i]-=part[i-p2];
            }
            part[i]%=mod;
            j++;
        }
    }
}

ll modpow(ll a,ll b){
    a%=mod;
    ll res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

ll modinv(ll a){
    return modpow(a,mod-2);
}

struct Segment_Lazy{
    ll INF=INT_MIN;
    vector<ll>segtree,prop,dat;
    Segment_Lazy(int n){
        segtree.resize(2<<(32-__builtin_clz(n)));
        prop.resize(2<<(32-__builtin_clz(n)));
        dat.resize(n);
    }
    void seg_init(int nod, int l, int r){
        if(l==r){
            segtree[nod]=dat[l];
            return;
        }
        int mid=(l+r)>>1;
        seg_init(nod<<1,l,mid);
        seg_init(nod<<1|1,mid+1,r);
        segtree[nod]=max(segtree[nod<<1],segtree[nod<<1|1]);
    }
    void seg_prop(int nod, int l, int r){
        ll mid=(l+r)>>1;
        prop[nod<<1]=max(prop[nod<<1],prop[nod]);
        segtree[nod<<1]=max(segtree[nod<<1],prop[nod]);
        prop[nod<<1|1]=max(prop[nod<<1|1],prop[nod]);
        segtree[nod<<1|1]=max(segtree[nod<<1|1],prop[nod]);
        prop[nod]=INF;
    }
    void seg_update(int nod, int l, int r, int s, int e, ll val){
        if(e<l || r<s)return;
        if(s<=l && r<=e) {
            segtree[nod] = max(segtree[nod], val);
            prop[nod] = max(prop[nod], val);
            return;
        }
        int mid=(l+r)>>1;
        seg_update(nod<<1,l,mid,s,e,val);
        seg_update(nod<<1|1,mid+1,r,s,e,val);
        segtree[nod]=max(segtree[nod<<1],segtree[nod<<1|1]);
    }
    ll seg_query(int nod, int l, int r, int s, int e){
        if(e<l || r<s)return 0;
        if(s<=l && r<=e){
            return segtree[nod];
        }
        seg_prop(nod,l,r);
        int mid=(l+r)>>1;
        return max(seg_query(nod<<1,l,mid,s,e),seg_query(nod<<1|1,mid+1,r,s,e));
    }
    void init(){
        seg_init(1,0,dat.size()-1);
    }
    void update(int s, int e, ll val){
        seg_update(1,0,dat.size()-1,s,e,val);
    }
    ll query(int s, int e){
        return seg_query(1,0,dat.size()-1,s,e);
    }
};


void solve(){
    ll i,j;
    ll n,m;
    cin>>n>>m;
    vector<ll>arr(n);
    vector<ll>eve(m+1),odd(m+1);
    for(i=0;i<n;i++)cin>>arr[i];
    eve[0]=1;
    for(i=0;i<n;i++){
        for(j=m;j>=arr[i];j--){
            eve[j]+=odd[j-arr[i]];
            eve[j]%=mod;
            odd[j]+=eve[j-arr[i]];
            odd[j]%=mod;
        }
    }
    ll ans=0;
    for(i=0;i<=m;i++){
        ans+=(eve[i]-odd[i])*part[m-i];
        ans%=mod;
    }
    if(ans<0)ans+=mod;
    cout<<ans<<'\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    preprocess();
    ll t=1;
    cin>>t;
#ifdef kidw0124
    clock_t st=clock();
#endif
    while(t--)solve();
#ifdef kidw0124
    debug<<clock()-st<<"ms\n";
#endif
}