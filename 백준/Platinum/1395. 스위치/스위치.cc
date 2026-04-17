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

const ll tsize=131072*8;
ll segtree[tsize*2],prop[tsize*2];
ll n,m;

void seg_relax(int nod, int l, int r) {
    if (prop[nod] == 0) return;
    segtree[nod]=(r-l+1)-segtree[nod];
    if (l < r) {
        prop[nod << 1]^=1;
        prop[nod << 1 | 1]^=1;
    }
    prop[nod] = 0;
}

ll seg_query(ll nod, ll l, ll r, ll s, ll e)
{
    seg_relax(nod, l, r);
    if(r<s||e<l){
        return 0;
    }
    if(s<=l&&r<=e)return segtree[nod];
    ll m=(l+r)>>1;
    return seg_query(nod<<1, l, m, s, e)+seg_query(nod<<1|1, m+1, r, s, e);
}

int seg_update(ll nod, ll l, ll r, ll s, ll e, ll val) {
    seg_relax(nod,l,r);
    if (r < s || e < l) return segtree[nod];
    if (s <= l && r <= e) {
        prop[nod]^=1;
        seg_relax(nod,l,r);
        return segtree[nod];
    }
    int m = (l + r) >> 1;
    seg_update(nod << 1, l, m, s, e, val);
    seg_update(nod << 1 | 1, m + 1, r, s, e, val);
    segtree[nod] = segtree[nod << 1] + segtree[nod << 1 | 1];
    return segtree[nod];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    cin>>m;
    for(i=0;i<m;i++){
        ll a,b,c;
        cin>>a;
//        for(j=0;j<8;j++){
//            cout<<segtree[j]<<' ';
//        }
//        cout<<'\n';
        switch(a){
        case 0:
            cin>>a>>b;
            a--,b--;
            if(a>b)swap(a,b);
            seg_update(1,0,n-1,a,b,1);
            break;
        case 1:
            cin>>a>>b;
            a--,b--;
            if(a>b)swap(a,b);
            cout<<seg_query(1,0,n-1,a,b)<<'\n';
        }
    }

    return 0;
}
