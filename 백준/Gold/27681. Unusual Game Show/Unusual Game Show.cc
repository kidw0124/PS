#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
//using namespace atcoder;
using ll = long long;
using pll = pair<ll,ll>;
using tlll = tuple<ll,ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
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
constexpr ll mod=998244353;
ll ipow(ll a, ll b){
    if(!b)return 1;
    else{
        ll now=ipow(a,b>>1);
        if(b&1)return now*now%mod*a%mod;
        else return now*now%mod;
    }
}

pair<bool,ll> func(ll sz, ll obj){
    if(sz==0 && obj==0)return {true,0};
    if(sz==0 || obj==0)return {false,0};
    for(ll i=0;i<10;i++){
        ll now=1<<sz>>1;
        ll nex=obj-now*i;
        if(nex<0)continue;
        if(nex%11)continue;
        else{
            auto [ret,ret2]=func(sz-1,nex/11);
            if(ret)return {true,ret2*10+i};
        }
    }
    return {false,0};
}

void solve(){
    ll i,j,k;
    ld d;
    ld p;
    cin>>d>>p;
    ld ans=0;
    ans+=p/d*2+(1-p)*(d-1)/d/(d-2);
    cout<<fixed<<setprecision(10)<<ans<<'\n';

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
    ll t=1;
    cin>>t;
#ifdef kidw0124
    clock_t st=clock();
#endif
    while(t--)solve();
#ifdef kidw0124
    debug<<clock()-st<<"ms\n";
#endif
}