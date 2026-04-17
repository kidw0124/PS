#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;

void solve() {
    ll i,j;
    ll n;
    cin>>n;
    vector<pll>arr(n+1),brr(n+1);
    vector<ll>dp(n+1,INT_MIN);
    for(i=1;i<=n;i++)cin>>arr[i].first>>arr[i].second;
    for(i=1;i<=n;i++)cin>>brr[i].first>>brr[i].second;
    vector<pll>crr(n+1);
    for(i=1;i<=n;i++){
        crr[i]= {brr[i].second, i};
    }
    sort(crr.begin(), crr.end());
    dp[0]=0;
    for(i=1;i<=n;i++){
        for(j=0;j<i;j++){
            ll d=abs(arr[crr[i].second].first-arr[crr[j].second].first)
                    +abs(arr[crr[i].second].second-arr[crr[j].second].second);
            if(brr[crr[j].second].second+d<=brr[crr[i].second].second){
                dp[crr[i].second]=max(dp[crr[i].second],
                                      dp[crr[j].second]+brr[crr[i].second].second
                                      -max(brr[crr[j].second].second+d,brr[crr[i].second].first));
            }
        }
    }
    cout<<*max_element(dp.begin(), dp.end());
}

int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
//    cin >> tc;
    while (tc--) solve();
}