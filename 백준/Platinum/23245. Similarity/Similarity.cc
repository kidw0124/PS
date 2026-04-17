#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n;
vector<pair<ll,ll>>arr,brr,prefix2;
const ll tsize=131072*8;
ll segtree[tsize*2],prop[tsize*2];

bool cmp(pair<ll,ll> a, pair<ll,ll> b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    else return a.first<b.first;
}

void seg_relax(ll nod, ll l, ll r)
{
    if(prop[nod]==0)return;
    if(l<r){
        ll m=(l+r)>>1;
        segtree[nod<<1]+=(m-l+1)*prop[nod];
        prop[nod<<1]+=prop[nod];
        segtree[nod<<1|1]+=(r-m)*prop[nod];
        prop[nod<<1|1]+=prop[nod];
    }
    prop[nod]=0;
}

ll seg_query(ll nod, ll l, ll r, ll s, ll e)
{
    if(r<s||e<l){
        return 0;
    }
    if(s<=l&&r<=e)return segtree[nod];
    seg_relax(nod, l, r);
    ll m=(l+r)>>1;
    return seg_query(nod<<1, l, m, s, e)+seg_query(nod<<1|1, m+1, r, s, e);
}

void seg_update(ll nod, ll l, ll r, ll s, ll e, ll val) {
    if(r<s||e<l)return;
    if(s<=l&&r<=e){
        segtree[nod]+=(r-l+1)*val;
        prop[nod]+=val;
        return;
    }
    seg_relax(nod, l, r);
    ll m=(l+r)>>1;
    seg_update(nod<<1, l, m, s, e, val);
    seg_update(nod<<1|1, m+1, r, s, e, val);
    segtree[nod]=segtree[nod<<1]+segtree[nod<<1|1];
}

int main(){
    ll i,j;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    arr.resize(n);
    for(i=0;i<n;i++)cin>>arr[i].first;
    for(i=0;i<n;i++)cin>>arr[i].second;
//    for(i=0;i<n;i++){
//        cout<<i<<' '<<arr[i].first<<' '<<arr[i].second<<'\n';
//    }
    sort(arr.begin(),arr.end(),cmp);
//    for(i=0;i<n;i++){
//        cout<<i<<' '<<arr[i].first<<' '<<arr[i].second<<'\n';
//    }
    vector<ll> small(n),big(n);
    for(i=0;i<n;i++){
        small[i]=seg_query(1,0,1000000,0,arr[i].second-1);
        seg_update(1,0,1000000,arr[i].second,arr[i].second,1);
    }
    memset(segtree,0,sizeof(segtree));
    memset(prop,0,sizeof(prop));
    for(i=n-1;i>=0;i--){
        big[i]=seg_query(1,0,1000000,arr[i].second+1,1000000);
        seg_update(1,0,1000000,arr[i].second,arr[i].second,1);
    }
    ll ans=0;
    for(i=0;i<n;i++){
//        cout<<i<<small[i]<<' '<<big[i]<<'\n';
        ans+=small[i]*big[i];
    }
    cout<<ans;

}
