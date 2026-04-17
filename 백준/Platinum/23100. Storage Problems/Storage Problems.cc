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

ll mod = 167772161;

void solve(ll testcase){
    ll i, j, k;
    ll n,m;
    cin>>n>>m;
    vector<ll>arr(n);
    for(auto&k:arr)cin>>k;
    vector<vector<vector<ll>>>dp1(n,vector<vector<ll>>(n+1,vector<ll>(m+1)));
    dp1[0][0][0]=1;
    dp1[0][1][arr[0]]=1;
    for(i=1;i<n;i++){
        for(j=0;j<=n;j++){
            for(k=0;k<m+1;k++){
                dp1[i][j][k]+=dp1[i-1][j][k];
                if(dp1[i][j][k]>=mod)dp1[i][j][k]-=mod;
            }
            for(k=arr[i];k<m+1;k++){
                if(j)dp1[i][j][k]+=dp1[i-1][j-1][k-arr[i]];
                if(dp1[i][j][k]>=mod)dp1[i][j][k]-=mod;
            }
        }
    }
    vector<vector<vector<ll>>>dp2(n,vector<vector<ll>>(dp1.back().begin(),dp1.back().end()));
    for(i=0;i<n;i++){
        for(j=1;j<n;j++){
            for(k=0;k<m+1;k++){
                if(j&&k>=arr[i]){
                    dp2[i][j][k]-=dp2[i][j-1][k-arr[i]];
                    if(dp2[i][j][k]<0)dp2[i][j][k]+=mod;
                }
            }
            ll ans=0;
            for(k=m-arr[i]+1;k<=m;k++){
                ans+=dp2[i][j][k];
                if(ans>=mod)ans-=mod;
            }
            cout<<ans<<' ';
        }
        cout<<'\n';
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