#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pll =pair<ll,ll>;
using tlll = tuple<ll,ll,ll>;
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

void solve(){
    ll i,j,k;
    ll n,m;
#ifndef ONLINE_JUDGE
    clock_t st=clock();
#endif
    cin>>n>>m;
    vector<pll>arr(n+m+1);
    for(i=1;i<=n;i++){
        cin>>arr[i].first;
        arr[i].second=1;
    }
    for(i=n+1;i<=n+m;i++){
        cin>>arr[i].first;
        arr[i].second=2;
    }
    sort(arr.begin(), arr.end());
    vector<ll>dp(n+m+1);
    vector<vector<ll>>sum(3,vector<ll>(n+m+1));
    vector<vector<int>>cnt(3,vector<int>(n+m+1)),las(3,vector<int>(n+m+1));
    vector<vector<int>>pre(3,vector<int>(n+m+1));
    vector<int>ridx(n+m+1);
    for(i=1;i<=n+m;i++){
        cnt[1][i]=cnt[1][i-1];
        cnt[2][i]=cnt[2][i-1];
        sum[1][i]=sum[1][i-1];
        sum[2][i]=sum[2][i-1];
        las[1][i]=las[1][i-1];
        las[2][i]=las[2][i-1];
        sum[arr[i].second][i]+=arr[i].first;
        cnt[arr[i].second][i]++;
        las[arr[i].second][i]=i;
    }
    pre[arr[n+m].second][n+m]=n+m;
    for(i=n+m-1;i>0;i--){
        pre[1][i]=pre[1][i+1];
        pre[2][i]=pre[2][i+1];
        pre[arr[i].second][i]=i;
    }
    ll cnt1=0,cnt2=0;
    vector<vector<int>>idx(n+m+1);
    idx[m].push_back(0);
    for(i=1;i<=n+m;i++){
        if(arr[i].second==1)cnt1++;
        if(arr[i].second==2)cnt2++;
        idx[cnt1-cnt2+m].push_back(i);
        ridx[i]=cnt1-cnt2+m;
    }
    for(i=1;i<=n+m;i++){
        ll type=arr[i].second;
        ll optype=3-type;
        dp[i]=1e18;
        if(las[optype][i])dp[i]=min(dp[i],dp[i-1]+abs(arr[i].first-arr[las[optype][i]].first));
        if(pre[optype][i])dp[i]=min(dp[i],dp[i-1]+abs(arr[i].first-arr[pre[optype][i]].first));
        ll ri= std::lower_bound(idx[ridx[i]].begin(), idx[ridx[i]].end(),i)-idx[ridx[i]].begin();
        if(ri>0){
            j=idx[ridx[i]][ri-1];
            dp[i]=min(dp[i],dp[j]+abs(sum[1][i]-sum[1][j]-sum[2][i]+sum[2][j]));
        }
    }
    cout<<dp[n+m]<<'\n';
#ifndef ONLINE_JUDGE
    cout<<clock()-st<<'\n';
#endif

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
    while(t--)solve();
}