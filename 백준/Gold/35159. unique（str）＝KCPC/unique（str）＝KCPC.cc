#define private public
#include <bitset>
#undef private
#include <bits/stdc++.h>
#include <immintrin.h>
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("inline")
using namespace std;
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
using ll = long long;
using ull = unsigned long long;
using pll = pair<int, int>;
#define debug \
  if constexpr (ddebug) cout << "[DEBUG] "
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ld= double;
void solve(int testcase) {
    int i,j,k;
    string str;
    cin>>str;
    vector<ll>kss,css,pss;
    for(i=0;i<str.size();i++){
        if(str[i]=='K')kss.push_back(i);
    }
    ll ans=0,cnt=0;
    for(i=0;i<kss.size();i++){
        ans+=kss[i]-i;
    }
    for(i=0;i<str.size();i++){
        if(str[i]=='C'){
            css.push_back(cnt++);
        }
        else if(str[i]=='P'){
            pss.push_back(cnt++);
        }
    }
    vector<ll>pfx(css.size()-1);
    vector<ll>sfx(css.size()-1);
    ll pp=pss.size()-1;
    for(i=0;i<css.size()-1;i++){
        pfx[i]=(i?pfx[i-1]:0)+css[i]-i;
    }
    for(i=css.size()-1;i>0;i--){
        while(pp>=0&&pss[pp]>css[i]){
            pp--;
        }
        sfx[i-1]+=(i!=css.size()-1?sfx[i]:0)+pss.size()-1-pp;
        pfx[i-1]+=sfx[i-1];
    }
    cout<<ans+ranges::min(pfx)<<"\n";
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
 
void preprocess() {
    int i,j,k;
}
 
signed main() {
    setup();
    preprocess();
    int t = 1;
//    cin >> t;
    for (int testcase = 1; testcase <= t; testcase++) {
        solve(testcase);
    }
    return 0;
}
