#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#ifdef kidw0124
constexpr ll TSIZE = 1<<3;
#else
constexpr ll TSIZE = 1<<20;
#endif

struct lazy_seg{
    vector<ll> dat,seg,lazy;
    lazy_seg(ll n){
        dat.resize(n+1);
        seg.resize(TSIZE<<1);
        lazy.resize(TSIZE<<1);
    }
    void seg_prop(ll nod, ll l, ll r){
        if(lazy[nod]==0)return;
        if(l<r) {
            ll mid = (l + r) >> 1;
            lazy[nod << 1] += lazy[nod];
            seg[nod << 1] += lazy[nod] * (mid - l + 1);
            lazy[nod << 1 | 1] += lazy[nod];
            seg[nod << 1 | 1] += lazy[nod] * (r - mid);
        }
        lazy[nod]=0;
    }
    void seg_add(ll nod, ll l, ll r, ll s, ll e, ll val){
        if(r<s||e<l)return;
        if(s<=l && r<=e){
            seg[nod]+=(r-l+1)*val;
            lazy[nod]+=val;
            return;
        }
        seg_prop(nod,l,r);
        ll mid=(l+r)>>1;
        seg_add(nod<<1,l,mid,s,e,val);
        seg_add(nod<<1|1,mid+1,r,s,e,val);
        seg[nod]=seg[nod<<1]+seg[nod<<1|1];
    }
    ll seg_query(ll nod, ll l, ll r, ll s, ll e){
        if(r<s||e<l)return 0;
        if(s<=l && r<=e){
            return seg[nod];
        }
        seg_prop(nod,l,r);
        ll mid=(l+r)>>1;
        return seg_query(nod<<1,l,mid,s,e)+seg_query(nod<<1|1,mid+1,r,s,e);
    }
};

int main(){
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);cin.tie(0);
#endif
    ll i,j;
    ll n,m;
#ifdef kidw0124
    constexpr ll MAX = 4;
#else
    constexpr ll MAX=1e5+1;
#endif
    cin>>n>>m;
    vector<ll>hrr(n),arr(n),brr(n);
    for(i=0;i<n;i++){
        cin>>hrr[i];
    }
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=0;i<n;i++){
        cin>>brr[i];
    }
    lazy_seg seg(MAX);
    ll tmp=0;
    for(i=0;i<m;i++){
        seg.seg_add(1,0,MAX,0,hrr[i]-1,-brr[i]);
        seg.seg_add(1,0,MAX,hrr[i],MAX,arr[i]);
        tmp+=brr[i]*hrr[i];
    }
    ll ans=1e18;
    for(i=m;i<=n;i++){
        ll st=0,en=MAX;
        while(st<en){
            ll mid=(st+en)>>1;
            ll q=seg.seg_query(1,0,MAX,mid,mid);
            if(q>=0){
                en=mid;
            }
            else{
                st=mid+1;
            }
        }
        ans=min(ans,tmp+seg.seg_query(1,0,MAX,0,st-1));
        if(i==n)break;
        seg.seg_add(1,0,MAX,0,hrr[i-m]-1,brr[i-m]);
        seg.seg_add(1,0,MAX,hrr[i-m],MAX,-arr[i-m]);
        seg.seg_add(1,0,MAX,0,hrr[i]-1,-brr[i]);
        seg.seg_add(1,0,MAX,hrr[i],MAX,arr[i]);
        tmp-=brr[i-m]*hrr[i-m];
        tmp+=brr[i]*hrr[i];
    }
    cout<<ans;


}