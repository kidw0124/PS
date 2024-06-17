#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

#ifdef ONLINE_JUDGE
constexpr bool ddebug=false;
#else
constexpr bool ddebug=true;
#endif

void solve(){
    ll i,j,k;
    ll n;
    cin >> n;
    deque<ll>arr(n);
    for(i=0;i<n;i++)cin>>arr[i];
    vector<ll>dp(n);
    ll ans=0;
    for(i=0;i<n;i++){
        dp[i]=0;
        for(j=i+1;j<n;j++){
            dp[j]=0;
            for(k=i;k<j;k++){
                dp[j]=max(dp[j],dp[k]+(arr[j]^arr[k]));
            }
            ans=max(ans,dp[j]+(arr[i]^arr[j]));
        }
    }
    cout<<ans<<'\n';
}


int main(){
    if(!ddebug){
        ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    }
    else{
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
    ll t=1;
    cin>>t;
    while(t--)solve();
}