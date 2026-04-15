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
using pll = pair<ll, ll>;
#define debug \
  if constexpr (ddebug) cout << "[DEBUG] "
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ld= long double;

void solve(ll testcase) {
    ll i,j,k;
    ll n;
    cin>>n;
    ll sn=(sqrt((ld)8*n+1.01)+1)/2;
    vector<ll>comb(sn+1);
    for(i=1;i<=sn;i++){
        comb[i]=i*(i-1)/2;
        if(comb[i]>n){
            sn=i-1;
            comb.resize(sn+1);
            break;
        }
    }
    if(comb[sn]==n){
        cout<<sn+1<<"\n";
        for(i=0;i<sn;i++){
            cout<<"1 "<<i+2<<"\n";
        }
    }
    else{
        ll rem=sn*(sn+1)/2-n;
        for(i=ranges::lower_bound(comb,rem)-comb.begin();i>=1;i--){
            ll r2=rem-comb[i];
            for(j=ranges::lower_bound(comb,r2)-comb.begin();j>=0;j--){
                if(ranges::binary_search(comb,r2-comb[j])){
                    k=ranges::lower_bound(comb,r2-comb[j])-comb.begin();
                    break;
                }
            }
            if(j>=0)break;
        }
        auto [a,b,c]=tuple{i,j,k};
        ll rr=sn+1-a-b-c;
        assert(rr>=0);
        cout<<1+3+a+b+c+2*rr<<"\n";
        for(i=0;i<3+rr;i++){
            cout<<"1 "<<i+2<<"\n";
        }
        for(i=0;i<a;i++){
            cout<<"2 "<<5+rr+i<<"\n";
        }
        for(i=0;i<b;i++){
            cout<<"3 "<<5+rr+a+i<<"\n";
        }
        for(i=0;i<c;i++){
            cout<<"4 "<<5+rr+a+b+i<<"\n";
        }
        for(i=0;i<rr;i++){
            cout<<i+5<<" "<<5+rr+a+b+c+i<<"\n";
        }
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

void preprocess() {
    ll i, j, k;
}

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
