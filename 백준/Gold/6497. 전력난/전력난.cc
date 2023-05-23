#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef __float128 LD;
typedef __int128_t LL;
typedef __uint128_t ULL;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

void setup(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

void preprocess(){

}
#ifdef ONLINE_JUDGE
const int TSIZE = 1<<20; // always 2^k form && n <= TSIZE
#else
const int TSIZE = 1<<3; // always 2^k form && n <= TSIZE
#endif
struct segment{
    vector<ll> segtree, prop,dat;
    segment(int n){
        segtree.resize(TSIZE*2);
        prop.resize(TSIZE*2);
        dat.resize(n);
    }
    void seg_init(int nod, int l, int r) {
        if (l == r) segtree[nod] = dat[l];
        else {
            int m = (l + r) >> 1;
            seg_init(nod << 1, l, m);
            seg_init(nod << 1 | 1, m + 1, r);
            segtree[nod] = segtree[nod << 1] + segtree[nod << 1 | 1];
        }
    }

    void seg_relax(int nod, int l, int r) {
        if (prop[nod] == 0) return;
        if (l < r) {
            int m = (l + r) >> 1;
            segtree[nod << 1] += (m - l + 1) * prop[nod];
            prop[nod << 1] += prop[nod];
            segtree[nod << 1 | 1] += (r - m) * prop[nod];
            prop[nod << 1 | 1] += prop[nod];
        }
        prop[nod] = 0;
    }

    ll seg_query(int nod, int l, int r, int s, int e) {
        if (r < s || e < l) return 0;
        if (s <= l && r <= e) return segtree[nod];
        seg_relax(nod, l, r);
        int m = (l + r) >> 1;
        return seg_query(nod << 1, l, m, s, e) + seg_query(nod << 1 | 1, m + 1, r, s, e);
    }

    void seg_update(int nod, int l, int r, int s, int e, int val) {
        if (r < s || e < l) return;
        if (s <= l && r <= e) {
            segtree[nod] += (r - l + 1) * val;
            prop[nod] += val;
            return;
        }
        seg_relax(nod, l, r);
        int m = (l + r) >> 1;
        seg_update(nod << 1, l, m, s, e, val);
        seg_update(nod << 1 | 1, m + 1, r, s, e, val);
        segtree[nod] = segtree[nod << 1] + segtree[nod << 1 | 1];
    }
    // usage:
    // seg_update(1, 0, n ‐ 1, qs, qe, val);
    // seg_query(1, 0, n ‐ 1, qs, qe);
};



void solve(ll testcase){
    ll i,j,k;
    ll n,m;
    cin>>n>>m;
    if(n==0)exit(0);
    priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<>>pq;
    ll ans=0;
    for(i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        pq.push({c,a,b});
        ans+=c;
    }
    vector<ll>grp(n);
    iota(all(grp),0);
    auto _find = [&grp](ll n,auto&&_find){
        if(grp[n]==n)return n;
        else return grp[n]=_find(grp[n],_find);
    };
    auto _union = [&grp,&_find](ll a, ll b,ll c){
        a=_find(a,_find);
        b=_find(b,_find);
        if(grp[a]==grp[b])return 0ll;
        else{
            grp[a]=grp[b];
            return c;
        }
    };
    while(!pq.empty()){
        auto [c,a,b]=pq.top();
        pq.pop();
        ans-=_union(a,b,c);
    }
    cout<<ans<<'\n';
}

int main() {
    setup();
    preprocess();
    ll t=INT_MAX;
    //cin>>t;
    for(ll testcase=1;testcase<=t;testcase++) {
        solve(testcase);
    }
    return 0;
}
