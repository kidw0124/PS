#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
ll gcd(ll a, ll b) {
    return b?gcd(b,a%b):a;
}
ll lcm(ll a, ll b) {
    if(a&&b)return a*(b/gcd(a,b));
    return a+b;
}
ll POW(ll a, ll b, ll rem) {
    ll p=1;
    for(; b; b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;
    return p;
}

vector<ll>arr;
ll n,m;
struct query{
    ll st,en,val;
    ll idx,ans;
};
vector<query>brr;
// example implementation of sum tree
const int TSIZE = 131072; // always 2^k form && n <= TSIZE
int segtree[TSIZE * 2], prop[TSIZE * 2],dat[TSIZE*2];
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
int seg_query(int nod, int l, int r, int s, int e) {
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
// seg_update(1, 0, n - 1, qs, qe, val);
// seg_query(1, 0, n - 1, qs, qe);
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    arr.resize(n);
    for(i=0;i<n;i++)cin>>arr[i];
    cin>>m;
    brr.resize(m);
    rep(i,0,m)cin>>brr[i].st>>brr[i].en>>brr[i].val,brr[i].idx=i;
    auto cmp=[](query l,query r){return l.val>r.val;};
    sort(brr.begin(),brr.end(),cmp);
    vector<pair<ll,ll>>crr(n);
    for(i=0;i<n;i++)crr[i]={arr[i],i};
    sort(crr.begin(),crr.end(),greater<pair<ll,ll>>());
    ll t=0;
    for(i=0;i<m;i++){
        while(crr[t].first>brr[i].val){
            seg_update(1,0,n-1,crr[t].second,crr[t].second,1);
            t++;
        }
        brr[i].ans=seg_query(1,0,n-1,brr[i].st-1,brr[i].en-1);
    }
    auto cmp2=[](query l,query r){return l.idx<r.idx;};
    sort(all(brr),cmp2);
    rep(i,0,m)cout<<brr[i].ans<<'\n';
    return 0;
}
