#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//gp_hash_table<int, int> table;
using namespace __gnu_pbds;
using ll = long long;
using LL = __int128;
using pll = pair<ll, ll>;
using ld = long double;

struct Q{
    LL p, q;
    void norm(){
        p= abs(p);
        q= abs(q);
        if(p == 0){
            q = 1;
            return;
        }
        if(q==0){
            p=0;
            return;
        }
        LL g = __gcd(p, q);
        if(g == 0)g = 1;
        p /= g;
        q /= g;
    }
    bool operator<(const Q &a)const{
        if(p != a.p)return p < a.p;
        return q < a.q;
    }
    bool operator==(const Q &a)const{
        return p == a.p && q == a.q;
    }
};

struct chash{
    size_t operator()(const Q&v)const{
        size_t ret = 0;
        ret ^= hash<LL>()(v.p);
        ret ^= hash<LL>()(v.q^0x814814814);
        return ret;
    }
    size_t operator()(const pair<Q, Q>&v)const{
        size_t ret = 0;
        ret ^= hash<LL>()(v.first.p);
        ret ^= hash<LL>()(v.first.q^0x814);
        ret ^= hash<LL>()(v.second.p^0x814814);
        ret ^= hash<LL>()(v.second.q^0x814814814);
        return ret;
    }
};

void solve() {
    ll i,j;
    ll n,q;
    cin>>n;
    vector<int>arr(n),brr;
    for(i=0;i<n;i++)cin>>arr[i];
    map<int,int>rarr;
    brr=arr;
    sort(brr.begin(), brr.end());
    brr.erase(unique(brr.begin(), brr.end()), brr.end());
    for(i=0;i<brr.size();i++)rarr[brr[i]]=i;
    vector<int>cnt(brr.size());
    for(i=0;i<n;i++)arr[i]=rarr[arr[i]];
    cin>>q;
    int sn=sqrt(n);
    struct query{
        int l, r, idx;
    };
    vector<query>queries(q);
    for(i=0;i<q;i++){
        cin>>queries[i].l>>queries[i].r;
        queries[i].l--;
        queries[i].idx=i;
    }
    sort(queries.begin(), queries.end(), [&](query a, query b){
        int as=a.l/sn, bs=b.l/sn;
        if(as!=bs)return as<bs;
        return (as&1)?a.r>b.r:a.r<b.r;
    });
    int s=0,e=0,now=0;
    vector<ll>ans(q);
    for(i=0;i<q;i++){
        int l=queries[i].l, r=queries[i].r;
        while(s>l){
            s--;
            if(cnt[arr[s]]==0)now++;
            cnt[arr[s]]++;
        }
        while(e<r){
            if(cnt[arr[e]]==0)now++;
            cnt[arr[e]]++;
            e++;
        }
        while(s<l){
            cnt[arr[s]]--;
            if(cnt[arr[s]]==0)now--;
            s++;
        }
        while(e>r){
            e--;
            cnt[arr[e]]--;
            if(cnt[arr[e]]==0)now--;
        }
        ans[queries[i].idx]=now;
    }
    for(auto x:ans) {
        cout << x << '\n';
    }
}

int main() {
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    clock_t beg = clock();
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
//    preprocess();
    ll t=1;
//    cin>>t;
    while(t--)solve();
#ifdef kidw0124
    cout<<clock()-beg<<"ms\n";
#endif
}
