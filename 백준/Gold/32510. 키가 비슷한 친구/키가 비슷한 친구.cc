#include <bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr ll MAXN=1<<20;
constexpr ll MAXR=500'000;
constexpr ll INF=1e9;

vector<ll>seg(MAXN,INF);

void seg_in(ll nod, ll l, ll r, ll idx,ll val){
    if(l==r && l==idx){
        seg[nod]=min(seg[nod],val);
    }
    else if(l>idx||r<idx||l>r){
        return;
    }
    else{
        ll mid=(l+r)>>1;
        seg_in(nod<<1,l,mid,idx,val);
        seg_in(nod<<1|1,mid+1,r,idx,val);
        seg[nod]=min(seg[nod<<1],seg[nod<<1|1]);
    }
}

void seg_out(ll nod, ll l, ll r, ll idx){
    if(l==r){
        seg[nod]=INF;
    }
    else if(l>idx||r<idx){
        return;
    }
    else{
        seg[nod]=INF;
        ll mid=(l+r)>>1;
        seg_out(nod<<1,l,mid,idx);
        seg_out(nod<<1|1,mid+1,r,idx);
    }
}

ll seg_query(ll nod, ll l, ll r, ll s, ll e){
    if(s<=l && r<=e)return seg[nod];
    else if(e<l||r<s||l>r){
        return INF;
    }
    else{
        ll mid=(l+r)>>1;
        return min(seg_query(nod<<1,l,mid,s,e),seg_query(nod<<1|1,mid+1,r,s,e));
    }
}

void solve(){
    ll i,j;
    ll n,k;
    cin>>n>>k;
    vector<ll>arr(n);
    ll ans=0;
    for(i=0;i<n;i++){
        cin>>arr[i];
        seg_in(1,0,MAXR,arr[i],i);
//        cout<<"!";
//        for(j=0;j<8;j++){
//            cout<<seg[j]<<' ';
//        }
//        cout<<'\n';
        ll ret=seg_query(1,0,MAXR,max(0ll,arr[i]-k),arr[i]);
        ans+=i-ret;
    }
    for(i=0;i<n;i++){
        seg_out(1,0,MAXR,arr[i]);
    }
    cout<<ans<<'\n';

}

int main(){
#ifndef kidw0124
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
#endif
    ll T;
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        cout<<"Case #"<<tc<<'\n';
        solve();
    }
    return 0;
}