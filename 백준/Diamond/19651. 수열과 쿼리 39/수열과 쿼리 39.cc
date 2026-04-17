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

auto enumerate(const auto& data) {
    return data | views::transform([i = 0](const auto& value) mutable {
        return make_pair(i++, value);
    });
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

struct Fenwick{
    vector<ll>fenwick;
    vector<ll>dat;
    Fenwick(int n){
        fenwick.resize(n+1);
        dat.resize(n+1);
    }
    void update(int idx, ll val){
        dat[idx]+=val;
        while(idx<fenwick.size()){
            fenwick[idx]+=val;
            idx+=(idx&-idx);
        }
    }
    void init(){
        for(int i=1;i<dat.size();i++){
            update(i,dat[i]);
            dat[i]>>=1;
        }
    }
    ll sum(int idx){
        ll ret=0;
        while(idx){
            ret+=fenwick[idx];
            idx-=(idx&-idx);
        }
        return ret;
    }
    ll query(int s, int e){
        if(s>e)return 0;
        return sum(e)-sum(s-1);
    }
};

struct Segment_Lazy{
    vector<ll>segtree,prop,dat;
    Segment_Lazy(){
        segtree.resize(TSIZE);
        prop.resize(TSIZE);
        dat.resize(1);
    }
    Segment_Lazy(int n){
        segtree.resize(2<<(32-__builtin_clz(n)));
        prop.resize(2<<(32-__builtin_clz(n)));
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
    void seg_prop(int nod, int l, int r){
        ll mid=(l+r)>>1;
        prop[nod<<1]+=prop[nod];
        segtree[nod<<1]+=prop[nod]*(mid-l+1);
        prop[nod<<1|1]+=prop[nod];
        segtree[nod<<1|1]+=prop[nod]*(r-mid);
        prop[nod]=0;
    }
    void seg_update(int nod, int l, int r, int s, int e, ll val){
        if(e<l || r<s)return;
        if(s<=l && r<=e) {
            segtree[nod]+=val*(r-l+1);
            prop[nod]+=val;
            return;
        }
        int mid=(l+r)>>1;
        seg_update(nod<<1,l,mid,s,e,val);
        seg_update(nod<<1|1,mid+1,r,s,e,val);
        segtree[nod] = segtree[nod << 1] + segtree[nod << 1 | 1];
    }
    ll seg_query(int nod, int l, int r, int s, int e){
        if(e<l || r<s)return 0;
        if(s<=l && r<=e){
            return segtree[nod];
        }
        seg_prop(nod,l,r);
        int mid=(l+r)>>1;
        return seg_query(nod<<1,l,mid,s,e)+seg_query(nod<<1|1,mid+1,r,s,e);
    }
    void init(){
        seg_init(1,0,dat.size()-1);
    }
    void update(int s, int e, ll val){
        seg_update(1,0,dat.size()-1,s,e,val);
    }
    ll query(int s, int e){
        return seg_query(1,0,dat.size()-1,s,e);
    }
};

struct Segment_Zero{
    struct Node{
        ll l,r,mx;
        ll len;
    };
    vector<Node>segtree;
    vector<ll>dat;
    Segment_Zero(){
        segtree.resize(TSIZE);
        dat.resize(1);
    }
    Segment_Zero(int n){
        segtree.resize(2<<(32-__builtin_clz(n)));
        dat.resize(n);
    }
    void seg_init(int nod, int l, int r){
        if(l==r){
            ll p=(dat[l]==0);
            segtree[nod]={p,p,p,1};
            return;
        }
        int mid=(l+r)>>1;
        seg_init(nod<<1,l,mid);
        seg_init(nod<<1|1,mid+1,r);
        if((segtree[nod].l=segtree[nod<<1].l)==mid-l+1)segtree[nod].l+=segtree[nod<<1|1].l;
        if((segtree[nod].r=segtree[nod<<1|1].r)==r-mid)segtree[nod].r+=segtree[nod<<1].r;
        segtree[nod].mx=max({segtree[nod<<1].mx,segtree[nod<<1|1].mx
                             ,segtree[nod<<1].r+segtree[nod<<1|1].l});
        segtree[nod].len=r-l+1;
    }
    void seg_update(int nod, int l, int r, int idx, ll val){
        if(idx<l || r<idx)return;
        if(l==r){
            dat[l]+=val;
            ll p=(dat[l]==0);
            segtree[nod]={p,p,p,1};
            return;
        }
        int mid=(l+r)>>1;
        seg_update(nod<<1,l,mid,idx,val);
        seg_update(nod<<1|1,mid+1,r,idx,val);
        if((segtree[nod].l=segtree[nod<<1].l)==mid-l+1)segtree[nod].l+=segtree[nod<<1|1].l;
        if((segtree[nod].r=segtree[nod<<1|1].r)==r-mid)segtree[nod].r+=segtree[nod<<1].r;
        segtree[nod].mx=max({segtree[nod<<1].mx,segtree[nod<<1|1].mx
                                    ,segtree[nod<<1].r+segtree[nod<<1|1].l});
    }
    Node seg_query(int nod, int l, int r, int s, int e){
        if(e<l || r<s)return {0,0,0,0};
        if(s<=l && r<=e)return segtree[nod];
        int mid=(l+r)>>1;
        auto lef=seg_query(nod<<1,l,mid,s,e);
        auto rig=seg_query(nod<<1|1,mid+1,r,s,e);
        return {
            lef.l+(lef.l==lef.len?rig.l:0),
            rig.r+(rig.r==rig.len?lef.r:0),
            max({lef.mx,rig.mx,lef.r+rig.l}),
            lef.len+rig.len
        };
    }
    void init(){
        seg_init(1,0,dat.size()-1);
    }
    void update(int idx, ll val){
        if(idx<0||idx>=dat.size())return;
        seg_update(1,0,dat.size()-1,idx,val);
    }
    ll query(int s, int e){
        if(s>e)return 0;
        return seg_query(1,0,dat.size()-1,s,e).mx;
    }
};

void preprocess(){
    ll i,j;

}

void solve(ll testcase){
    ll i,j;
    ll n,q,m;
    cin>>n;
    vector<ll>arr(n);
    Segment_Zero seg(n-2);
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=0;i<n-2;i++){
        seg.dat[i]=arr[i+2]-arr[i+1]-(arr[i+1]-arr[i]);
    }
    seg.init();
    cin>>q;
    for(i=0;i<q;i++){
        ll a,b,c,d,e;
        cin>>a;
        if(a==1){
            cin>>b>>c>>d>>e;
            b--,c--;
            seg.update(b-1,e-d);
            seg.update(b-2,d);
            seg.update(c-1,-d-(c-b+1)*e);
            seg.update(c,d+(c-b)*e);
        }
        else{
            cin>>b>>c;
            b--,c--;
            cout<<seg.query(b,c-2)+2<<'\n';
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