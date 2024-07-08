#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct segtree{
    struct Node{
        ll lprifix, rprefix, sum, maxsum;
    };
    vector<ll>dat;
    vector<Node>seg;
    segtree(){
        dat.resize(1<<20);
        seg.resize(1<<21);
    }
    void seg_init(int nod, int l, int r){
        if(l==r){
            seg[nod]={dat[l], dat[l], dat[l], dat[l]};
            return;
        }
        int mid=(l+r)>>1;
        seg_init(nod<<1, l, mid);
        seg_init(nod<<1|1, mid+1, r);
        seg[nod].sum=seg[nod<<1].sum+seg[nod<<1|1].sum;
        seg[nod].lprifix=max(seg[nod<<1].lprifix, seg[nod<<1].sum+seg[nod<<1|1].lprifix);
        seg[nod].rprefix=max(seg[nod<<1|1].rprefix, seg[nod<<1|1].sum+seg[nod<<1].rprefix);
        seg[nod].maxsum=max({seg[nod].lprifix, seg[nod].rprefix, seg[nod<<1].maxsum, seg[nod<<1|1].maxsum, seg[nod<<1].rprefix+seg[nod<<1|1].lprifix});
    }
    Node seg_query(int nod, int l, int r, int s, int e){
        if(e<l||r<s) return {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        if(s<=l&&r<=e) return seg[nod];
        int mid=(l+r)>>1;
        Node L=seg_query(nod<<1, l, mid, s, e);
        Node R=seg_query(nod<<1|1, mid+1, r, s, e);
        Node ret;
        ret.sum=L.sum+R.sum;
        ret.lprifix=max(L.lprifix, L.sum+R.lprifix);
        ret.rprefix=max(R.rprefix, R.sum+L.rprefix);
        ret.maxsum=max({ret.lprifix, ret.rprefix, L.maxsum, R.maxsum, L.rprefix+R.lprifix});
        return ret;
    }
};

void solve() {
    ll i,j,cnt=0;
    vector<ll> spf(1'000'000+1);
    for(i=2;i<=1'000'000;++i) {
        if(spf[i]==0) {
            for(j=i;j<=1'000'000;j+=i) {
                if(spf[j]==0) spf[j]=i;
            }
        }
    }
    vector<ll> primes(1e6+1);
    primes[1]=0;
    for(i=2;i<=1'000'000;++i) {
        primes[i]=primes[i/spf[i]]+1;
    }
    for(i=1;i<=1'000'000;++i) {
        if(primes[i]==1)primes[i]=-2;
        else primes[i]--;
    }
    segtree seg;
    seg.dat=primes;
    seg.seg_init(1, 1, 1'000'000);
    while(cin>>i>>j, i!=-1&&j!=-1) {
        cout<< ++cnt <<". " << seg.seg_query(1, 1, 1'000'000, i, j).maxsum << '\n';
    }
}

int main() {
#ifdef kidw0124
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    int t = 1;
    //cin >> t;
    while (t--) solve();
}