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

const int TSIZE = 1<<20; // always 2^k form && n <= TSIZE
ll M = 0;
struct segment{
    vector<ll> segtree, prop,dat;
    segment(){
        segtree.resize(TSIZE*2);
        prop.resize(TSIZE*2);
        dat.resize(M+1);
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
    cin>>n;
    vector<pll>arr(n);
    vector<ll>cnt(M+1);
    for(i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
        M=max(arr[i].second,M);
        cnt.resize(max((ll)cnt.size(),M+1));
        cnt[arr[i].second]++;
    }
    segment A, B;
    sort(all(arr),greater<>());
    B.dat[0]=cnt[0];
    for(i=1;i<=M;i++){
        A.dat[i]=i*cnt[i];
        B.dat[i]=cnt[i];
    }
    ll ans=0;
    A.seg_init(1,0,M);
    B.seg_init(1,0,M);
    for(i=0;i<n;i++){
        ll lo = A.seg_query(1,0,M,0,arr[i].second-1);
        ll hi = A.seg_query(1,0,M,arr[i].second+1,M);
        ll l = B.seg_query(1,0,M,0,arr[i].second-1);
        ll h = B.seg_query(1,0,M,arr[i].second+1,M);

        ans+=arr[i].first*(arr[i].second*l-lo)+arr[i].first*(hi-arr[i].second*h);

        A.seg_update(1,0,M,arr[i].second,arr[i].second,-arr[i].second);
        B.seg_update(1,0,M,arr[i].second,arr[i].second,-1);
    }
    cout<<ans;
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
