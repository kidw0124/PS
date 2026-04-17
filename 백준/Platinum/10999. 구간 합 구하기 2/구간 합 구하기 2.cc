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
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

const ll TSIZE = 1048576; // always 2^k form && n <= TSIZE
ll segtree[TSIZE * 2], prop[TSIZE * 2];
    vl arr;
void seg_init(ll nod, ll l, ll r) {
    if (l == r) segtree[nod] = arr[l];
    else {
        ll m = (l + r) >> 1;
        seg_init(nod << 1, l, m);
        seg_init(nod << 1 | 1, m + 1, r);
        segtree[nod] = segtree[nod << 1] + segtree[nod << 1 | 1];
    }
}
void seg_relax(ll nod, ll l, ll r) {
    if (prop[nod] == 0) return;
    if (l < r) {
        ll m = (l + r) >> 1;
        segtree[nod << 1] += (m - l + 1) * prop[nod];
        prop[nod << 1] += prop[nod];
        segtree[nod << 1 | 1] += (r - m) * prop[nod];
        prop[nod << 1 | 1] += prop[nod];
    }
    prop[nod] = 0;
}
ll seg_query(ll nod, ll l, ll r, ll s, ll e) {
    if (r < s || e < l) return 0;
    if (s <= l && r <= e) return segtree[nod];
    seg_relax(nod, l, r);
    ll m = (l + r) >> 1;
    return seg_query(nod << 1, l, m, s, e) + seg_query(nod << 1 | 1, m + 1, r, s
            , e);
}
void seg_update(ll nod, ll l, ll r, ll s, ll e, ll val) {
    if (r < s || e < l) return;
    if (s <= l && r <= e) {
        segtree[nod] += (r - l + 1) * val;
        prop[nod] += val;
        return;
    }
    seg_relax(nod, l, r);
    ll m = (l + r) >> 1;
    seg_update(nod << 1, l, m, s, e, val);
    seg_update(nod << 1 | 1, m + 1, r, s, e, val);
    segtree[nod] = segtree[nod << 1] + segtree[nod << 1 | 1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,n,m,k;
    cin>>n>>m>>k;
    arr.resize(n);
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    seg_init(1,0,n-1);
    for(i=0;i<m+k;i++){
        ll a,b,c,d;
        cin>>a>>b>>c;
        if(a&1){
            cin>>d;
            seg_update(1,0,n-1,b-1,c-1,d);
        }
        else{
            cout<<seg_query(1,0,n-1,b-1,c-1)<<'\n';
        }
    }

    return 0;
}
