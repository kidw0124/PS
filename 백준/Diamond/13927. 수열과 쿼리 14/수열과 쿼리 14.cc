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
constexpr int MAXN=1e5,step=1e3;

bitset<MAXN>ans;
template <size_t _Nw> int _find_kth(const _Base_bitset<_Nw>& bs, int k) {
    // cout<<"BS!!! "<<bs.count()<<" "<<k<<'\n';
//    if (bs.count() <= k)return -1;
    using word_type = std::remove_all_extents_t<decltype(bs._M_w)>;
    auto popcount=[](word_type x) {
        if (sizeof(word_type)==sizeof(int)) return __builtin_popcount(x);
        else return __builtin_popcountll(x);
    };
    int sz=sizeof(word_type)*8;
    for (int i = 0; i < _Nw; i++) {
        int cnt=popcount(bs._M_w[i]);
        if (k>=cnt){
            k-=cnt;
        }
        else {
            for (int j = 0; j < sz; j++) {
                if ((bs._M_w[i] >> j) & 1) {
                    if (k == 0) return i*sz+j;
                    k--;
                }
            }
        }
    }
    return -1;
}

struct SQRTTree {
    int n,leafst;
    bitset<MAXN> tree[1<<33-__builtin_clz(MAXN/step+1)];
    SQRTTree(int _n) {
        n=_n;
        assert(n<=MAXN);
        leafst=1<<32-__builtin_clz(n/step+1);
    }
    void build(const vector<int>&arr) {
        for (int i=0;i<n;i+=step) {
            for (int j=i;j<min(n,i+step);j++) {
                assert(arr[j]<MAXN);
                tree[i/step|leafst].set(arr[j]);
            }
        }
        for (int i=leafst-1;i>0;i--) {
            tree[i]=tree[i<<1]|tree[i<<1|1];
        }
    }
    void query_block(int l, int r) {
        l|=leafst,r|=leafst;
        while (l<=r) {
            if (l&1)ans|=tree[l++];
            if (r&1^1)ans|=tree[r--];
            l>>=1,r>>=1;
        }
    }
    void query(int l, int r,const vector<int>&arr) {
        if (l/step==r/step) {
            for (int i=l;i<=r;i++){
//                assert(arr[i]<MAXN);
                ans.set(arr[i]);
            }
            return;
        }
        for (int i=l;i<(l/step+1)*step;i++){
//            assert(arr[i]<MAXN);
            ans.set(arr[i]);
        }
        for (int i=(r/step)*step;i<=r;i++){
//            assert(arr[i]<MAXN);
            ans.set(arr[i]);
        }
        if (l/step+1<=r/step-1)query_block(l/step+1,r/step-1);
    }
};

void solve(ll testcase) {
    ll i,j;
    int n;
    cin>>n;
    vector<int>arr(n),tmp;
    for (auto&k:arr)cin>>k;
    tmp=arr;
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for (auto&x:arr) {
        x=lower_bound(tmp.begin(), tmp.end(), x)-tmp.begin();
        assert(x<MAXN);
    }
    assert(n<=MAXN);
    SQRTTree seg(n);
    seg.build(arr);
    ll q;
    cin>>q;
    int p=0;
    while(q--) {
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        int l=(a*(ll)max(p,0)+b)%n;
        int r=(c*(ll)max(p,0)+d)%n;
        if (l>r)swap(l,r);
        assert(0<=l&&r<=n-1);
        ans.reset();
        seg.query(l,r,arr);
#ifdef kidw0124
        cout<<l<<' '<<r<<' '<<k<<" : ";
        for (int i = ans._Find_first();
             i < ans.size();
             i = ans._Find_next(i))
            cout << i << "("<<tmp[i]<<") ";
        cout << " = "<<_find_kth(ans,k-1)<<"\n";
        // cout<<ans.to_string()<<" = ";
#endif
        p=_find_kth(ans,k-1);
        if(p>-1)p=tmp[p];
        cout<<p<<'\n';
    }
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
    // cin >> t;
    for (ll testcase = 1; testcase <= t; testcase++) {
        solve(testcase);
    }
    return 0;
}