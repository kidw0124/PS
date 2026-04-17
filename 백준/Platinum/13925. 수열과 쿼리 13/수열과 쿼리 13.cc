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
    const int TSIZE = 1<<2; // always 2^k form && n <= TSIZE
#else
    const int TSIZE = 1<<20; // always 2^k form && n <= TSIZE
#endif
const ll MOD = 1e9+7;
struct segment{
    vector<ll> segtree, dat;
    vector<pair<ll,ll>> prop;
    segment(ll n){
        segtree.resize(TSIZE*2);
        prop.resize(TSIZE*2,{1,0});
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
            segtree[nod] = (segtree[nod << 1] + segtree[nod << 1 | 1]) % MOD;
        }
    }

    void seg_relax(int nod, int l, int r) {
        if (prop[nod] == make_pair(1ll,0ll)) return;
        if (l < r) {
            int m = (l + r) >> 1;
            segtree[nod << 1] *= prop[nod].first;
            segtree[nod << 1 | 1] *= prop[nod].first;
            segtree[nod << 1] %= MOD;
            segtree[nod << 1 | 1] %= MOD;
            segtree[nod << 1] += (m - l + 1) * prop[nod].second % MOD;
            segtree[nod << 1 | 1] += (r - m) * prop[nod].second % MOD;
            segtree[nod << 1] %= MOD;
            segtree[nod << 1 | 1] %= MOD;
            prop[nod << 1] = {prop[nod].first*prop[nod << 1].first%MOD,
                              (prop[nod << 1].second * prop[nod].first + prop[nod].second)%MOD};
            prop[nod << 1 | 1] = {prop[nod].first*prop[nod << 1 | 1].first%MOD,
                              (prop[nod << 1 | 1].second * prop[nod].first + prop[nod].second)%MOD};
            prop[nod] = {1,0};
        }
    }

    ll seg_query(int nod, int l, int r, int s, int e) {
        if (r < s || e < l) return 0;
        if (s <= l && r <= e) return segtree[nod]%MOD;
        seg_relax(nod, l, r);
        int m = (l + r) >> 1;
        return (seg_query(nod << 1, l, m, s, e) + seg_query(nod << 1 | 1, m + 1, r, s, e))%MOD;
    }

    void seg_update(int nod, int l, int r, int s, int e, pll val) {
        if (r < s || e < l) return;
        if (s <= l && r <= e) {
            segtree[nod] *= val.first;
            segtree[nod]%=MOD;
            segtree[nod] += (r - l + 1) * val.second % MOD;
            segtree[nod]%=MOD;
            prop[nod].first *= val.first;
            prop[nod].first%=MOD;
            prop[nod].second *= val.first;
            prop[nod].second%=MOD;
            prop[nod].second += val.second;
            prop[nod].second%=MOD;
            return;
        }
        seg_relax(nod, l, r);
        int m = (l + r) >> 1;
        seg_update(nod << 1, l, m, s, e, val);
        seg_update(nod << 1 | 1, m + 1, r, s, e, val);
        segtree[nod] = (segtree[nod << 1] + segtree[nod << 1 | 1])%MOD;
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
        b--,c--;
        if(a<4)cin>>d;
        if(a==4){
            cout<<S.seg_query(1,0,n-1,b,c)<<'\n';
        }
        else{
            switch (a) {
                case 1:
                    S.seg_update(1,0,n-1,b,c,{1,d});
                    break;
                case 2:
                    S.seg_update(1,0,n-1,b,c,{d,0});
                    break;
                case 3:
                    S.seg_update(1,0,n-1,b,c,{0,d});
                    break;

            }
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
