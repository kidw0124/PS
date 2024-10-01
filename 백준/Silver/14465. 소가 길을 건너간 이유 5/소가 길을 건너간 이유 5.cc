#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll i,j;
    /// N개의 횡단보도가 있다
    /// arr[i] : i번이 고장났으면 1, 고장안났으면 0
    /// arr[i]+arr[i+1]+...+arr[i+k-1]
    /// i~i+k-1까지 고장난것의 개수
    /// sum[0]=0;
    /// sum[1]=arr[0];
    /// sum[2]=arr[0]+arr[1];
    /// sum[i] = arr[0]+arr[1]+...+arr[i-1]
    /// sum[i+k]-sum[i] : i~i+k-1까지 고장난것의 개수
    /// 이것의 최솟값
    ll n,k,b;
    cin>>n>>k>>b;
    vector<ll>arr(n),sum(n+1);
    for(i=0;i<b;i++){
        ll x;
        cin>>x;
        arr[x-1]=1;
    }
    // sum[0]=0; => 선언할때 초기화가 이미 됨
    for(i=1;i<=n;i++){
        sum[i]=sum[i-1]+arr[i-1];
    }
    ll ans=k;
    // i+k <= n
    for(i=0;i+k<=n;i++){
        ans=min(ans,sum[i+k]-sum[i]);
    }
    cout<<ans;
}

int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}