#include<bits/stdc++.h>
using namespace std;
#ifdef ATCODER
#include<atcoder/all>
using namespace atcoder;
#endif
using ll = long long;
using pll = pair<ll,ll>;
using tlll = tuple<ll,ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto &x : a)
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "

#ifndef kidw0124
const ll TSIZE = 1 << 20; // always 2^k form && n <= TSIZE
#else
const ll TSIZE = 1 << 3; // always 2^k form && n <= TSIZE
#endif

void yes(){
    cout<<"Yes\n";
}

void no(){
    cout<<"No\n";
}

void preprocess(){

}

constexpr ll mod=998244353;

void solve(){
    ll i,j,k;
    ll n,q;
    cin>>n>>q;
    unordered_map<string,ll>idx;
    string tmp;
    getline(cin,tmp);
    for(i=0;i<n;i++){
        getline(cin,tmp);
        idx[tmp]=i;
    }
    vector<ll>par(n);
    for(i=0;i<n;i++)par[i]=i;

    function<ll(ll)>_find=[&](ll x){
        return par[x]==x?x:par[x]=_find(par[x]);
    };
    function<void(ll,ll)>_merge=[&](ll x,ll y){
        assert(_find(x)==x || _find(y)==y);
        x=_find(x);
        y=_find(y);
        par[y]=x;
        par[x]=x;
    };

    for(i=0;i<q;i++){
        getline(cin,tmp);
        string tmp1=tmp.substr(0,tmp.find(','));
        string tmp2=tmp.substr(tmp.find(',')+1);
        tmp2=tmp2.substr(0,tmp2.find(','));
        string tmp3=tmp.substr(tmp.find_last_of(',')+1);
        if(tmp3=="2")swap(tmp1,tmp2);
        if(_find(idx[tmp1])!=_find(idx[tmp2])){
            _merge(idx[tmp1], idx[tmp2]);
        }
        else{
            par[idx[tmp1]]=idx[tmp1];
            par[idx[tmp2]]=idx[tmp1];

        }
    }
    vector<string>ans;
    for(auto &[nation,ind]:idx){
        if(_find(ind)==ind)ans.pb(nation);
    }
    sort(all(ans));
    cout<<ans.size()<<"\n";
    for(auto &x:ans) {
        cout<<x<<"\n";
    }

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    preprocess();
    ll t=1;
//    cin>>t;
#ifdef kidw0124
    clock_t st=clock();
#endif
    while(t--)solve();
#ifdef kidw0124
    debug<<clock()-st<<"ms\n";
#endif
}