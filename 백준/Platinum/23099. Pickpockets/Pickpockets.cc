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
#ifdef kidw0124
ll maxbit=4;
#else
ll maxbit=64;
#endif
void solve(ll testcase){
    ll i, j, k;
    ll n,m;
    cin>>n>>m;
    vector<pll>robs(m);
    vector<vector<bool>>arr(n,vector<bool>(16));
    vector<vector<ll>>len(2'000'000);
    for(i=0;i<n;i++){
        cin>>j;
        if(j>16){
            cout<<"0\n";
            return;
        }
        for(k=0;k<j;k++){
            arr[i][k]=1;
        }
    }
    for(i=0;i<m;i++){
        cin>>robs[i].first>>robs[i].second;
    }
    vector<ll> brr;
    for(i=0;i<16;i++){
        for(j=0;j<n;j++){
            ll tmp=0;
            if(arr[j][i]){
                while(j<n&&arr[j][i]){
                    tmp++;
                    j++;
                }
                brr.push_back(tmp);
            }
        }
    }
    for(i=0;i<(1<<m);i++){
        ll tmp =0;
        for(k=0;k<m;k++){
            if(i>>k&1){
                tmp+=robs[k].first;
            }
        }
        if(i==1288){
            debug<<i<<' '<<tmp<<"!\n";
        }
//        debug<<tmp<<' '<<i<<'\n';
        if(tmp<n+1)len[tmp].push_back(i);
    }
    vector<vector<bool>>dp(brr.size(),vector<bool>(1<<m));
    for(i=0;i<brr.size();i++){
        for(auto j:len[brr[i]]){
            if(i==0){
                dp[i][j]=1;
            }
            else{
                for(k=0;k<(1<<m);k++){
                    if(j==32&&k==1371){
                        debug<<"!!!!\n";
                    }
                    if(j&k)continue;
                    else{
                        dp[i][j|k]=dp[i][j|k]||dp[i-1][k];
                    }
                }
            }
        }
        for(j=0;j<(1<<m);j++){
            if(dp[i][j]){
                bitset<16>bs(j);
                debug<<i+1<<' '<<bs<<'\n';
            }
        }
    }
    if(brr.size()==0){
        cout<<"0\n";
        return;
    }
    ll ans=0;
    for(i=0;i<(1<<m);i++){
        if(dp[brr.size()-1][i]){
            ll tmp =0;
            for(k=0;k<m;k++){
                if(i>>k&1){
                    tmp+=robs[k].second;
                }
            }
            ans=max(ans,tmp);
        }
    }
    cout<<ans;
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