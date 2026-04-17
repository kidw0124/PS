#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll,ll>;
using pld = pair<ld,ld>;
#pragma GCC optimize("O3, unroll-loops")
#pragma GCC target("avx,avx2,fma")
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif

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
    ll n,i,j;
    cin>>n;
    vector<ll>arr(n),sum(n+1);
    for(auto&k:arr)cin>>k;
    vector<vector<ll>>dp(10);
    dp[0].push_back(0);
    for(i=0;i<n;i++){
        sum[i+1]=sum[i]+arr[i];
        dp[sum[i+1]%10].push_back(i+1);
    }
    for(i=0;i<n;i++){
        ll q=sum[i]%10;
        if(arr[i]==0)cout<<"1 ";
        else{
            auto t= std::lower_bound(dp[q].begin(), dp[q].end(),i);
            if(t+1!=dp[q].end()){
                cout<<*(t+1)-i<<' ';
            }
            else cout<<"-1 ";

        }
    }
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