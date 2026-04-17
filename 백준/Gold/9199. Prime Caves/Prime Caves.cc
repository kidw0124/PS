#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;
#ifdef kidw0124
    constexpr bool xdebug = true;
#else
    constexpr bool xdebug = false;
#endif
#define debug if constexpr (xdebug) cout<<"[DEBUG] "
void setup(){
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
#endif
}

vector<vector<ll>>arr(1024,vector<ll>(1024));
vector<pll>iloc(1<<20);
bitset<(1<<20)>primes;

void preprocess(){
    ll i,j,k;
    ll s=512,e=512;
    ll now=1;
    iloc[now]={s,e};
    arr[s][e]=1;
    ll x=1;
    for(i=1;now<=1e6;i++){
        for(j=0;j<i;j++){
            e+=x;
            now++;
            iloc[now]={s,e};
            arr[s][e]=now;
        }
        for(j=0;j<i;j++){
            s-=x;
            now++;
            iloc[now]={s,e};
            arr[s][e]=now;
        }
        x=-x;
    }
    primes.set();
    primes[0]=primes[1]=0;
    for(i=2;i<=1e6;i++){
        if(primes[i]){
            for(j=i*i;j<=1e6;j+=i){
                primes[j]=0;
            }
        }
    }
}

void solve(ll testcase){
    ll i,j,k;
    ll a,b;
    while(cin>>a>>b,a){
        vector<vector<pll>>dp(1024,vector<pll>(1024));
        vector<vector<bool>>vis(1024,vector<bool>(1024));
        auto [s,e] = iloc[b];
        dp[s][e]={primes[b],primes[b]?b:0};
        pll ans=dp[s][e];
        vis[s][e]=1;
        for(i=s+1;i<1024;i++){
            for(j=0;j<1024;j++){
                if(arr[i][j]>a)continue;
                if(vis[i-1][j]){
                    dp[i][j]=dp[i-1][j];
                    vis[i][j]=1;
                }
                if(j&&vis[i-1][j-1]){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
                    vis[i][j]=1;
                }
                if(j!=1023&&vis[i-1][j+1]){
                    dp[i][j]=max(dp[i][j],dp[i-1][j+1]);
                    vis[i][j]=1;
                }
                if(primes[arr[i][j]])dp[i][j]={dp[i][j].first+1,arr[i][j]};
//                if(ans<dp[i][j]){
//                    debug<<i<<' '<<j<<' '<<ans.first<<' '<<ans.second<<' '<<arr[i][j]<<' '<<dp[i][j].first<<' '<<dp[i][j].second<<'\n';
//                }
                if(vis[i][j])ans=max(ans,dp[i][j]);
            }
        }
        cout<<ans.first<<' '<<ans.second<<'\n';

    }

}


int main(){
    setup();
    preprocess();
    ll te=1;
//    cin>>te;
    for(ll tc=1;tc<=te;tc++){
        solve(tc);
    }
}