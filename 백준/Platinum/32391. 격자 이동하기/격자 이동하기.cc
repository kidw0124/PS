#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using ll = long long;
using LL = __int128;
using pll = pair<ll, ll>;

void preprocess() {
    ;
}

constexpr ll MOD = 1e9+7;

ll modpow(ll a,ll b) {
    ll res=1;
    while(b) {
        if(b&1)res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

ll modinv(ll a) {
    return modpow(a,MOD-2);
}

void solve() {
    ll i,j;
    ll n;
    pll dest;
    cin>>dest.first>>dest.second>>n;
    ll MAX=dest.first+1+dest.second+1;
    vector<ll>fact(MAX+1),inv(MAX+1);
    fact[0]=1;
    for(i=1;i<=MAX;i++)fact[i]=fact[i-1]*i%MOD;
    inv[MAX]=modinv(fact[MAX]);
    for(i=MAX-1;i>=0;i--)inv[i]=inv[i+1]*(i+1)%MOD;
    vector<pll>arr(n+2);
    arr[0]={-1,-1},arr[n+1]=dest;
    for(i=1;i<=n;i++)cin>>arr[i].first>>arr[i].second;
    vector<vector<ll>>cnt(n+2,vector<ll>(n+2)),grp(n+2);
    vector<pll>dp(n+2);
    vector<ll>rgrp(n+2);
    auto nCr=[&](ll n,ll r){
        if(n<0||r<0||n<r)return 0LL;
        return fact[n]*inv[r]%MOD*inv[n-r]%MOD;
    };
    for(i=0;i<=n+1;i++) {
        for(j=0;j<=n+1;j++) {
            if(i==j)continue;
            if(arr[i].first<arr[j].first && arr[i].second<arr[j].second) {
                ll dx=arr[j].first-arr[i].first-1,dy=arr[j].second-arr[i].second-1;
                assert(dx>=0 && dy>=0 && dx+dy>=0 && dx+dy<=MAX);
                cnt[i][j]=cnt[j][i]=nCr(dx+dy,dx);
                grp[i].push_back(j);
                rgrp[j]++;
            }
        }
    }
    queue<ll>que;
    for(i=0;i<=n+1;i++){
        if(rgrp[i]==0)que.push(i);
    }
    assert(que.size()==1 && que.front()==0);
    dp[0]={1,1};
    while(!que.empty()) {
        ll cur=que.front();
        que.pop();
        for(auto nxt:grp[cur]) {
            if(dp[cur].first+1==dp[nxt].first) {
                dp[nxt].second=(dp[nxt].second+dp[cur].second*cnt[cur][nxt]%MOD)%MOD;
            }
            else if(dp[cur].first+1>dp[nxt].first) {
                dp[nxt].first=dp[cur].first+1;
                dp[nxt].second=dp[cur].second*cnt[cur][nxt]%MOD;
            }
            rgrp[nxt]--;
            if(rgrp[nxt]==0)que.push(nxt);
        }
    }
    cout<<dp[n+1].second<<'\n';
}

int main() {
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    clock_t beg = clock();
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    preprocess();
    ll t=1;
//    cin>>t;
    while(t--)solve();
#ifdef kidw0124
    cout<<clock()-beg<<"ms\n";
#endif
}
