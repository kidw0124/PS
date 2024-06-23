#include<bits/stdc++.h>
using namespace std;
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
    int i,j,k;
    ll n,m;
    cin>>n>>m;
    vector<string>arr(m);
    for(i=0;i<m;i++)cin>>arr[i];
    vector<ll>west(n),east(n),sumwest(n+1),sumeast(n+1);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(arr[i][j]=='W')west[j]++;
            else east[j]++;
        }
    }
    for(i=0;i<n;i++){
        sumwest[i+1]=sumwest[i]+west[i];
        sumeast[i+1]=sumeast[i]+east[i];
    }
    ll now=0;
    auto calc=[&](ll x){
        return sumeast[x]+sumwest[n]-sumwest[x];
    };
    for(i=1;i<=n;i++){
        if(calc(i)<calc(now))now=i;
    }
    cout<<now<<' '<<now+1<<'\n';
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