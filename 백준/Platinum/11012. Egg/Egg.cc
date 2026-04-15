#define private public
#include <bitset>
#undef private
#include <bits/stdc++.h>
#include <immintrin.h>
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("inline")
using namespace std;
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
#define debug \
  if constexpr (ddebug) cout << "[DEBUG] "
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ld= long double;

struct PST{
    struct Node{ll l,r,v;};
    vector<Node>nodes;vector<ll>root;vector<ll>arr;
    PST(ll n=0,ll qmax=0){
        root.reserve(qmax+5);
        nodes.reserve(4*(n+1)+20*qmax+5);
        arr.resize(n+1);
        root.push_back(init(0,n));
    }
    ll init(ll s,ll e){
        ll cur=nodes.size();
        nodes.push_back({-1,-1,0});
        if(s<e){
            ll m=s+e>>1;
            nodes[cur].l=init(s,m),nodes[cur].r=init(m+1,e);
        }
        return cur;
    }
    ll add(ll s,ll e,ll pre,ll pos,ll val){
        ll cur=nodes.size();
        nodes.push_back(nodes[pre]);
        if(s==e){
            nodes[cur].v+=val;
            return cur;
        }
        ll m=s+e>>1;
        if(pos<=m)nodes[cur].l=add(s,m,nodes[pre].l,pos,val);
        else nodes[cur].r=add(m+1,e,nodes[pre].r,pos,val);
        nodes[cur].v=nodes[nodes[cur].l].v+nodes[nodes[cur].r].v;
        return cur;
    }
    ll query(ll s,ll e,ll u,ll v,ll l,ll r){
        if(r<s||e<l)return 0;
        if(l<=s&&e<=r)return nodes[v].v-nodes[u].v;
        ll m=s+e>>1;
        return query(s,m,nodes[u].l,nodes[v].l,l,r)+query(m+1,e,nodes[u].r,nodes[v].r,l,r);
    }
};
// pst.init(0,n);
// pst.add(0,n,prev_root,pos,val);
// pst.query(0,n,root_u,root_v,l,r);

void solve(ll testcase) {
    ll i,j;
    ll m;
    ll n;
    cin>>n>>m;
    vector<pll>arr(n);
    ll MAXN=1e5+1;
    PST pst(MAXN,MAXN);
    for(auto&[x,y]:arr)cin>>x>>y,x++,y++;
    ranges::sort(arr);
    j=0;
    for(i=1;i<=MAXN;i++){
        pst.root.push_back(pst.root.back());
        while(j<n&&arr[j].first==i){
            pst.root.back()=pst.add(0,MAXN,pst.root.back(),arr[j].second,1);
            j++;
        }
    }
    ll ans=0;
    while(m--){
        ll a,b,c,d;
        cin>>a>>c>>b>>d;
        a++,b++,c++,d++;
        ans+=pst.query(0,MAXN,pst.root[a-1],pst.root[c],b,d);
    }
    cout<<ans<<"\n";
}

void setup() {
    if (ddebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    } else {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void preprocess() {
    ll i, j, k;
}

signed main() {
    setup();
    preprocess();
    ll t = 1;
    cin >> t;
    for (ll testcase = 1; testcase <= t; testcase++) {
        solve(testcase);
    }
    return 0;
}