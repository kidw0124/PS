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

void setup(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

void preprocess(){

}

#ifndef ONLINE_JUDGE
    const int TSIZE = 1<<4; // always 2^k form && n <= TSIZE
#else
    const int TSIZE = 1<<20; // always 2^k form && n <= TSIZE
#endif
struct segment{
    vector<ll> segtree, dat;
    vector<ll> prop;
    segment(ll n){
        segtree.resize(TSIZE*2,INT_MAX);
        prop.resize(TSIZE*2,INT_MAX);
        dat.resize(n+1);
    }
    segment(){
        segment(0);
    }
    void seg_init(int nod, int l, int r) {
        if (l == r) segtree[nod] = dat[l];
        else {
            int m = (l + r) >> 1;
            seg_init(nod << 1, l, m);
            seg_init(nod << 1 | 1, m + 1, r);
            segtree[nod] = min(segtree[nod << 1], segtree[nod << 1 | 1]);
        }
    }

    void seg_relax(int nod, int l, int r) {
        if (prop[nod] == INT_MAX) return;
        if (l < r) {
            int m = (l + r) >> 1;
            segtree[nod << 1] = min(segtree[nod<<1],prop[nod]);
            segtree[nod << 1|1] = min(segtree[nod<<1|1],prop[nod]);
            prop[nod << 1] = prop[nod << 1 | 1] = prop[nod];
            prop[nod] = INT_MAX;
        }
    }

    ll seg_query(int nod, int l, int r, int s, int e) {
        if (r < s || e < l) return INT_MAX;
        if (s <= l && r <= e) return segtree[nod];
        int m = (l + r) >> 1;
        return min(seg_query(nod << 1, l, m, s, e), seg_query(nod << 1 | 1, m + 1, r, s, e));
    }

    ll seg_update(int nod, int l, int r, int s, int e, ll val){
        if(r<s||e<l){
            return segtree[nod];
        }
        else if(l==r){
            return segtree[nod]=val;
        }
        else{
            ll m = (l+r)>>1;
            return segtree[nod]= min(seg_update(nod<<1,l,m,s,e,val),seg_update(nod<<1|1,m+1,r,s,e,val));
        }
    }
    // usage:
    // seg_update(1, 0, n ‐ 1, qs, qe, val);
    // seg_query(1, 0, n ‐ 1, qs, qe);
};

void solve(ll testcase){
    ll i,j,k;
    ll n,m;
    cin>>n;
    vector<ll>arr(n);
    segment S(n);
    for(i=0;i<n;i++) {
        cin>>S.dat[i];
    }
    S.seg_init(1,0,n-1);
    ll q;
    cin>>q;
    for(i=0;i<q;i++){
        ll a,b,c,d;
        cin>>a>>b>>c;
        if(a==1){
            S.seg_update(1,0,n-1,b-1,b-1,c);
        }
        else{
            cout<<S.seg_query(1,0,n-1,b-1,c-1)<<'\n';
        }
    }
}

int main() {
    setup();
    preprocess();
    ll t=1;
    //cin>>t;
    for(ll testcase=1;testcase<=t;testcase++) {
        solve(testcase);
    }
    return 0;
}
