#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
using tlll = tuple<ll,ll,ll>;
using ld = long double;

struct OFDC{
    // offline dynamic connectivity
    ll n,q; vector<ll>par, sz; vector<pll>query; stack<ll>st;
    vector<vector<pll>>tree; map<pll,ll>at;
    void update(ll node, ll tl, ll tr, ll l, ll r, pll v){
        if(r<tl||tr<l)return;
        if(l<=tl&&tr<=r) { tree[node].push_back(v); return; }
        ll tm=tl+tr>>1;
        update(node<<1,tl,tm,l,r,v);
        update(node<<1|1,tm+1,tr,l,r,v);
    }
    ll _find(ll x){ return x==par[x]?x:_find(par[x]); }
    bool _same(pll a){return _find(a.first)==_find(a.second);}
    bool _union(ll x, ll y){
        x=_find(x),y=_find(y); if(x==y)return false;
        if(sz[x]<sz[y])swap(x,y); par[y]=x; sz[x]+=sz[y]; st.push(y);
        return true;
    }
    void _delete(){
        if(st.empty())return;
        ll x=st.top(); st.pop(); sz[par[x]]-=sz[x]; par[x]=x;
    }
    void dfs(ll node, ll tl, ll tr){
        ll cnt=0;
        for(auto [x,y]:tree[node]) if(_union(x,y)) cnt++;
        if(tl==tr){if(query[tl].first)cout<<(_same(query[tl])?"YES":"NO")<<'\n';}
        else{ll tm=tl+tr>>1;dfs(node<<1,tl,tm), dfs(node<<1|1,tm+1,tr);}
        while(cnt--)_delete();
    }
    void run(ll _n, ll _q, vector<tlll>_query){
        // 1 : add, 2 : del, 3 : query
        n=_n, q=_q; query.resize(q); tree.resize(q<<2|1),par.resize(n+1);
        sz.assign(n+1,1),iota(par.begin(),par.end(),0);
        for(ll i=0;i<q;i++){
            auto [op,a,b]=_query[i]; if(a>b)swap(a,b);
            if(op==1) at[{a,b}]=i;
            else if(op==2) update(1,0,q-1,at[{a,b}],i,{a,b}), at.erase({a,b});
            else query[i]={a,b};
        }
        for(auto [x,y]:at) update(1,0,q-1,y,q-1,x);
        dfs(1,0,q-1);
    }
};

void solve() {
    ll i,j;
    ll n;
    cin >> n;
    vector<multiset<ll>>arr(n);
    for(i=0;i<n;i++){
        arr[i]={n-i,n-i};
    }
    vector<tlll>ans;
    for(i=n;i;i--){
        auto it1=ranges::find_if(arr,[i](auto x){return x.find(i)!=x.end();});
        auto it2=it1;
        if(*it1!=multiset({i,i})){
            it2=find_if(it1+1,arr.end(),[i](auto x){return x.find(i)!=x.end();});
        }
        auto x1=it1-arr.begin(),x2=it2-arr.begin();
        for(j=x2;j+1<i;j++){
            ans.push_back({j+1,i,*arr[j+1].begin()});
            arr[j+1].insert(i);
            arr[j].erase(arr[j].find(i));
            arr[j].insert(*arr[j+1].begin());
            arr[j+1].erase(arr[j+1].begin());
        }
        for(j=x1;j+1<i;j++){
            ans.push_back({j+1,i,*arr[j+1].begin()});
            arr[j+1].insert(i);
            arr[j].erase(arr[j].find(i));
            arr[j].insert(*arr[j+1].begin());
            arr[j+1].erase(arr[j+1].begin());
        }
    }
    cout<<ans.size()<<'\n';
    for(auto [a,b,c]:ans){
        cout<<a<<' '<<b<<' '<<c<<'\n';
    }
}

int main() {
#ifdef kidw0124
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    int tc = 1;
//     cin >> tc;
    while (tc--) solve();
}