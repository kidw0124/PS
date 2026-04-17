#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
#ifndef ONLINE_JUDGE
constexpr bool ddebug = true;
constexpr ll LGTSIZE = 3;
#else
constexpr bool ddebug = false;
constexpr ll LGTSIZE = 20;
#endif

const ll TSIZE = 1<<LGTSIZE;

void setup(){
    if(ddebug){
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
    else{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

struct Segment{
    vector<ll>segtree,dat;
    Segment(){
        segtree.resize(TSIZE);
        dat.resize(1);
    }
    Segment(int n){
        segtree.resize(2<<(32-__builtin_clz(n)));
        dat.resize(n);
    }
    void seg_init(int nod, int l, int r){
        if(l==r){
            segtree[nod]=dat[l];
            return;
        }
        int mid=(l+r)>>1;
        seg_init(nod<<1,l,mid);
        seg_init(nod<<1|1,mid+1,r);
        segtree[nod]=segtree[nod<<1]+segtree[nod<<1|1];
    }
    void seg_update(int nod, int l, int r, int idx, ll val){
        if(idx<l || r<idx)return;
        if(l==r){
            segtree[nod]+=val;
            dat[l]+=val;
            return;
        }
        int mid=(l+r)>>1;
        seg_update(nod<<1,l,mid,idx,val);
        seg_update(nod<<1|1,mid+1,r,idx,val);
        segtree[nod]=segtree[nod<<1]+segtree[nod<<1|1];
    }
    ll seg_query(int nod, int l, int r, int s, int e){
        if(e<l || r<s)return 0;
        if(s<=l && r<=e)return segtree[nod];
        int mid=(l+r)>>1;
        return seg_query(nod<<1,l,mid,s,e)+seg_query(nod<<1|1,mid+1,r,s,e);
    }
    void init(){
        seg_init(1,0,dat.size()-1);
    }
    void update(int idx, ll val){
        seg_update(1,0,dat.size()-1,idx,val);
    }
    ll query(int s, int e){
        return seg_query(1,0,dat.size()-1,s,e);
    }
};

struct Segment_Max_2{
    const ll INF = 1e18;
    vector<pll>segtree;
    vector<ll>dat;
    Segment_Max_2(){
        segtree.resize(TSIZE,{-INF,-INF});
        dat.resize(1);
    }
    Segment_Max_2(int n){
        segtree.resize(2<<(32-__builtin_clz(n)),{-INF,-INF});
        dat.resize(n);
    }
    void update_nod(int nod){
        priority_queue<ll>pq;
        pq.push(segtree[nod << 1].first);
        pq.push(segtree[nod << 1].second);
        pq.push(segtree[nod << 1|1].first);
        pq.push(segtree[nod << 1|1].second);
        segtree[nod].first=pq.top();
        pq.pop();
        segtree[nod].second=pq.top();
    }
    void seg_init(int nod, int l, int r){
        if(l==r){
            segtree[nod]= {dat[l],-INF};
            return;
        }
        int mid=(l+r)>>1;
        seg_init(nod<<1,l,mid);
        seg_init(nod<<1|1,mid+1,r);
        update_nod(nod);
    }
    void seg_update(int nod, int l, int r, int idx, ll val){
        if(idx<l || r<idx)return;
        if(l==r){
            segtree[nod]= {val,-INF};
            dat[l]=val;
            return;
        }
        int mid=(l+r)>>1;
        seg_update(nod<<1,l,mid,idx,val);
        seg_update(nod<<1|1,mid+1,r,idx,val);
        update_nod(nod);
    }
    pll seg_query(int nod, int l, int r, int s, int e){
        if(e<l || r<s)return {-INF,-INF};
        if(s<=l && r<=e)return segtree[nod];
        int mid=(l+r)>>1;
        auto lef=seg_query(nod<<1,l,mid,s,e),rig=seg_query(nod<<1|1,mid+1,r,s,e);
        priority_queue<ll>pq;
        pq.push(lef.first),pq.push(lef.second),pq.push(rig.first),pq.push(rig.second);
        pll tmp={pq.top(),0};
        pq.pop();
        tmp.second=pq.top();
        return tmp;
    }
    void init(){
        seg_init(1,0,dat.size()-1);
    }
    void update(int idx, ll val){
        seg_update(1,0,dat.size()-1,idx,val);
    }
    pll query(int s, int e){
        return seg_query(1,0,dat.size()-1,s,e);
    }
};

struct query1{
    ll idx, val;
};

struct query2{
    ll idx;
    ll k, i, j;
    ll val;
};

void preprocess(){
    ll i,j;

}

void solve(ll testcase){
    ll i,j;
    ll n,q;
    cin>>n;
    Segment_Max_2 seg(n);
    for(i=0;i<n;i++){
        cin>>seg.dat[i];
    }
    seg.init();
    cin>>q;
    for(i=0;i<q;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            seg.update(b-1,c);
        }
        else{
            auto [d,e]=seg.query(b-1,c-1);
            cout<<d+e<<'\n';
        }
    }

}

int main(){
    setup();
    preprocess();
    ll t=1;
//    cin>>t;
    for(int testcase=0;testcase<t;testcase++){
        solve(testcase+1);
    }

}