#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
using ordered_multi_set = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;
void m_erase(ordered_multi_set &OS, ll val) {
    ll index = OS.order_of_key(val);
    ordered_multi_set::iterator it = OS.find_by_order(index);
    if(*it == val) OS.erase(it);
}
using ld = long double;
using pll = pair<ll,ll>;
using pld = pair<ld,ld>;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif

#define debug if constexpr(ddebug) cout<<"[DEBUG] "

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

void preprocess(){
    ll i,j;
}
void solve(ll testcase){
    ll i, j, k;
    ll n,m,r;
    cin>>n>>m>>r;
    ll lc = lcm(++n,++m);
    ll p=r/lc;
    cout<<(r-r/n-r/m+p)<<' '<<p<<' '<<(r/m-p)<<' '<<(r/n-p)<<'\n';
}

int main(){
    setup();
    preprocess();
    ll t=1;
//    cin>>t;
    for(ll tc=0;tc<t;tc++){
        solve(tc+1);
    }
}