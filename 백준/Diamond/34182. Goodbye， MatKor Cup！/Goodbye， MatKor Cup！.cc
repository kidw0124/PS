#include <bits/stdc++.h>
#include <immintrin.h>
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
using ll = long long;
using pll = pair<ll, ll>;
#define debug \
  if constexpr (ddebug) cout << "[DEBUG] "
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ld= long double;
using uint = unsigned int;
using ull = unsigned long long;
const ld eps=1e-12;

const unsigned  mod  = 998244353;

void solve(ll testcase) {
    ll i,j,k;
    ll n;
    cin>>n;
    ll ans=0;
    auto calc=[](ll x)->ll{
        if(x==0)return 0;
        else if(x==1)return 1;
        else if(x==2)return 3;
        else if(x&1){
            return (x/2+1)*(x/2+2);
        }
        else{
            return (x/2)*(x/2+2)+1;
        }
    };
    while(calc(++ans)<n);
    cout<<ans<<"\n";
    vector<ll>arr;
    if(n==1){
        cout<<"1\n";
    }
    else if(n==2){
        cout<<"1 2\n";
    }
    else if(n==3){
        cout<<"1 3\n";
    }
    else if(ans&1){
        ll x=ans/2;
        ll now=0;
        ll maxi=calc(ans);
        for(i=0;i<x;i++){
            now+=ans-2*i+1;
            if(i==0)now-=maxi-n;
            arr.push_back(now);
        }
        arr.push_back(now+2);
        for(i=0;i<x-1;i++){
            arr.push_back(arr[x-i-2]+1);
        }
        arr.push_back(1);
    }
    else{
        ll x=ans/2;
        ll now=0;
        ll maxi=calc(ans);
        for(i=0;i<x-1;i++){
            now+=ans-2*i+1;
            if(i==0)now-=maxi-n;
            arr.push_back(now);
        }
        arr.push_back(now+2);
        arr.push_back(now+4);
        for(i=0;i<x-2;i++){
            arr.push_back(arr[x-i-3]+1);
        }
        arr.push_back(1);
    }
    for(auto &x:arr){
        cout<<x<<" ";
    }
}
void setup() {
    if (ddebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    } else {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void preprocess() { ll i, j, k; }

signed main() {
    setup();
    preprocess();
    ll t = 1;
//    cin >> t;
    for (ll testcase = 1; testcase <= t; testcase++) {
        solve(testcase);
    }
    return 0;
}
