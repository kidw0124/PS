#include<bits/stdc++.h>
namespace std{
    template<class A,class B>
    struct hash<pair<A,B>>{
        size_t operator() (const pair<A,B>& p) const {
            return std::rotl(hash<A>{}(p.first),1)^hash<B>{}(p.second);
        }
    };
}
using namespace std;
using ll = int;
using ld = long double;
using pll = pair<ll,ll>;
using tlll = tuple<ll,ll,ll>;

const ld eps=1e-12;
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
//        freopen("test.in","r",stdin);
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
struct Segment_Lazy_ass{
    vector<ll>segtree,prop,dat;
    Segment_Lazy_ass(){
        segtree.resize(TSIZE);
        prop.resize(TSIZE);
        dat.resize(1);
    }
    Segment_Lazy_ass(int n){
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
        prop[nod<<1]=prop[nod];
        segtree[nod<<1]=prop[nod]*(mid-l+1);
        prop[nod<<1|1]=prop[nod];
        segtree[nod<<1|1]=prop[nod]*(r-mid);
        prop[nod]=0;
    }
    void seg_update(int nod, int l, int r, int s, int e, ll val){
        if(e<l || r<s)return;
        if(s<=l && r<=e) {
            segtree[nod]=val*(r-l+1);
            prop[nod]=val;
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
struct Segment_Lazy_43{
    const ll INF = 1e18;
    struct Node{
        list<tlll>que;
        bool clear;
        ll cnt4;
        bool iszero;
    };
    vector<ll>segtree;
    vector<ll>dat;
    vector<Node>prop;
    Segment_Lazy_43(){
        segtree.resize(TSIZE);
        prop.resize(TSIZE);
        dat.resize(1);
    }
    Segment_Lazy_43(int n){
        segtree.resize(2<<(32-__builtin_clz(n)));
        prop.resize(2<<(32-__builtin_clz(n)));
        dat.resize(n);
    }
    void seg_init(int nod, int l, int r){
        if(l==r){
            segtree[nod]= dat[l];
            return;
        }
        int mid=(l+r)>>1;
        seg_init(nod<<1,l,mid);
        seg_init(nod<<1|1,mid+1,r);
        segtree[nod]=min(segtree[nod<<1],segtree[nod<<1|1]);
    }
    void insert(int nod,const tlll&op,int l, int r){
        auto [ty,x,y]=op;
        if(ty==2){
            if(segtree[nod]>=x)segtree[nod] -= x;
        }
        else if(ty==4){
            segtree[nod]=(ll)sqrt((ld)(segtree[nod]+eps));
        }
        else if(ty==3){
            segtree[nod]=x+l-y;
        }
        if(ty==3){
            prop[nod].que.clear();
            prop[nod].clear=1;
            prop[nod].cnt4=0;
            prop[nod].iszero=0;
            prop[nod].que.push_back(op);
        }
        else if(ty==4){
            if(prop[nod].cnt4<6){
                prop[nod].que.push_back(op);
                prop[nod].cnt4++;
            }
        }
        else{
            if(prop[nod].cnt4<6){
                if(prop[nod].que.size()) {
                    auto [tt, _, __] = prop[nod].que.back();
                    if(tt==2) {
                        get<1>(prop[nod].que.back())+=x;
                    }
                    else{
                        prop[nod].que.push_back(op);
                    }
                }
                else {
                    prop[nod].que.push_back(op);
                }
            }
            else if(!prop[nod].iszero){
                if(x==1) {
                    auto [tt, _, __] = prop[nod].que.back();
                    if (tt == 4) {
                        prop[nod].que.push_back(op);
                        prop[nod].iszero=1;
                    }
                }
            }
        }
        assert(prop[nod].que.size()<=100);
    }
    void seg_prop(int nod, int l, int r){
//        if(prop[nod].clear){
//            prop[nod<<1].que.clear();
//            prop[nod<<1|1].que.clear();
//            prop[nod<<1].cnt4=prop[nod<<1|1].cnt4=0;
//            prop[nod<<1].iszero=prop[nod<<1|1].iszero=false;
//        }
        ll mid=(l+r)>>1;
        for(auto&op:prop[nod].que){
            insert(nod<<1,op,l,mid);
            insert(nod<<1|1,op,mid+1,r);
        }
        prop[nod].clear=0;
        prop[nod].cnt4=0;
        prop[nod].iszero=0;
        prop[nod].que.clear();
    }
    void seg_update(int nod, int l, int r, int s, int e, int type, ll val){
        if(e<l || r<s)return;
        if(s<=l && r<=e) {
            if(type==2){
                insert(nod,{type,val,0},l,r);
            }
            else if(type==4){
                insert(nod,{type,val,0},l,r);
            }
            else{
                prop[nod].que.clear();
                prop[nod].clear=1;
                insert(nod,{type,val,e},l,r);
            }
            return;
        }
        seg_prop(nod,l,r);
        int mid=(l+r)>>1;
        seg_update(nod<<1,l,mid,s,e,type,val);
        seg_update(nod<<1|1,mid+1,r,s,e,type,val);
        segtree[nod]=min(segtree[nod<<1],segtree[nod<<1|1]);
    }
    ll seg_query(int nod, int l, int r, int s, int e){
        if(e<l || r<s)return INF;
        if(s<=l && r<=e){
            return segtree[nod];
        }
        seg_prop(nod,l,r);
        int mid=(l+r)>>1;
        return min(seg_query(nod<<1,l,mid,s,e),seg_query(nod<<1|1,mid+1,r,s,e));
    }
    void init(){
        seg_init(1,0,dat.size()-1);
    }
    void update(int s, int e, int type, ll val){
        seg_update(1,0,dat.size()-1,s,e,type,val);
    }
    ll query(int s, int e){
        return seg_query(1,0,dat.size()-1,s,e);
    }
};
struct Segment_Max{
    const ll INF = 1e18;
    vector<ll>segtree;
    vector<ll>dat;
    Segment_Max(){
        segtree.resize(TSIZE,-INF);
        dat.resize(1);
    }
    Segment_Max(int n){
        segtree.resize(2<<(32-__builtin_clz(n)),-INF);
        dat.resize(n);
    }
    void update_nod(int nod){
        segtree[nod]=max(segtree[nod<<1],segtree[nod<<1|1]);
    }
    void seg_init(int nod, int l, int r){
        if(l==r){
            segtree[nod]=dat[l];
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
            segtree[nod]=val;
            dat[l]=val;
            return;
        }
        int mid=(l+r)>>1;
        seg_update(nod<<1,l,mid,idx,val);
        seg_update(nod<<1|1,mid+1,r,idx,val);
        update_nod(nod);
    }
    ll seg_query(int nod, int l, int r, int s, int e){
        if(e<l || r<s)return -INF;
        if(s<=l && r<=e)return segtree[nod];
        int mid=(l+r)>>1;
        return max(seg_query(nod<<1,l,mid,s,e),seg_query(nod<<1|1,mid+1,r,s,e));
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

void preprocess(){
    ll i,j;

}

void solve(ll testcase){
    ll i,j;
    ll n,m;
    cin>>n;
    vector<int>par(n+1),in(n+1),out(n+1),sz(n+1),dep(n+1),top(n+1);
    vector<vector<ll>>grp(n+1),gidx(n+1);
    vector<ll>ridx(n+1);
    vector<tlll>edges(n);
    for(i=1;i<n;i++){
        auto&[x,y,z]=edges[i];
        cin>>x>>y>>z;
        grp[x].push_back(y);
        grp[y].push_back(x);
        gidx[x].push_back(i);
        gidx[y].push_back(i);
    }
    auto dfs_par_sz_dep = [&](int x,auto&&f)->void{
        dep[x]=dep[par[x]]+1;
        sz[x]=1;
        int p=0;
        for(auto&k:grp[x]){
            p++;
            if(k==par[x])continue;
            else{
                ridx[k]=gidx[x][p-1];
                par[k]=x;
                f(k,f);
                sz[x]+=sz[k];
                if(sz[k]>sz[grp[x][0]]){
                    swap(k,grp[x][0]);
                }
            }
        }
    };
    int ett_idx=0;
    auto dfs_ett = [&](int x,auto&&f)->void{
        in[x]=ett_idx++;
        for(auto&k:grp[x]){
            if(k==par[x])continue;
            else{
                top[k]=(k==grp[x][0]?top[x]:k);
                f(k,f);
            }
        }
        out[x]=ett_idx;
    };
    dfs_par_sz_dep(1,dfs_par_sz_dep);
    top[1]=1;
    dfs_ett(1,dfs_ett);
    Segment_Max seg(n);
    for(i=1;i<=n;i++){
        seg.dat[in[i]]=get<2>(edges[ridx[i]]);
    }
    seg.init();
    auto get_query = [&](int a, int b)->ll{
        ll ret=0;
        while(top[a]!=top[b]){
            if(dep[top[a]]<dep[top[b]])swap(a,b);
            ret=max(ret,seg.query(in[top[a]],in[a]));
            a=par[top[a]];
        }
        if(dep[a]<dep[b])swap(a,b);
        ret=max(ret,seg.query(in[b]+1,in[a]));
        return ret;
    };
    cin>>m;
    for(i=0;i<m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        if(x==1){
            auto [v,pv,_]=edges[y];
            if(par[v]!=pv)swap(v,pv);
            seg.update(in[v],z);
        }
        else{
            cout<<get_query(y,z)<<'\n';
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