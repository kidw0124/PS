#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll,ll>;

const ld PI = 3.1415926535897932384626433832705028;

void solve() {
    ll n;
    cin>>n;
    vector<ll>arr;
    for(ll i=0;i<(n/2);i++)arr.push_back((i+1)*710);
    for(ll i=0;i<(n/2);i++)arr.push_back(-(i+1)*710);
    if(n&1)arr.push_back(0);
    sort(arr.begin(), arr.end());
    for(ll i=0;i<n;i++){
        cout<<arr[i]<<'\n';
    }
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