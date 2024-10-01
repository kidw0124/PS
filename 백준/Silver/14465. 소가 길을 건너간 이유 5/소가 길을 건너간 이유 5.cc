#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll i,j;
    /// N개의 횡단보도가 있다
    /// arr[i] : i번 신호등이 있으면 1, 없으면 0
    /// 구하고 싶은 것
    /// arr[i],arr[i+1],...,arr[i+k-1] 모두 1이 되게 하기 위해
    /// 필요한 최소한의 신호등의 개수
    /// 이 중 이미 1인것이 가장 많은 구간
    /// arr[i]+arr[i+1]+...+arr[i+k-1]
    /// => 이미 있는 신호등의 개수
    /// 0, 1배열에서 "합=1의 개수"
    /// sum[i+k-1]-sum[i-1]의 최대
    /// i가 가능한 것 : n-k+1개 : O(N)
    ll n,k,b;
    cin>>n>>k>>b;
    vector<ll>arr(n,1),sum(n+1);
    for(i=0;i<b;i++){
        ll x;
        cin>>x;
        arr[x-1]=0;
    }
    // sum[0]=0; => 선언할때 초기화가 이미 됨
    for(i=1;i<=n;i++){
        sum[i]=sum[i-1]+arr[i-1];
    }
    ll ans=0;
    // i+k-1 <= n
    for(i=1;i+k-1<=n;i++){
        ll tmp=sum[i+k-1]-sum[i-1];
        if(ans<tmp){
            ans=tmp;
        }
    }
    cout<<k-ans;


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