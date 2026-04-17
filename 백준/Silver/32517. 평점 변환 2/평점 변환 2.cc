#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;

void solve() {
    ll i,j;
    ll n;
    cin>>n;
    vector<ll>brr(n),arr(n);
    for(auto &x:brr)cin>>x;
    ll sum=brr[0];
    arr[0]=brr[0];
    for(i=1;i<n;i++){
        if(sum<=i*brr[i]){
            arr[i]=brr[i];
        }
        else if(sum>i*(brr[i]+1)){
            arr[i]=brr[i]+1;
        }
        else{
            cout<<"-1\n";
            return;
        }
        sum+=arr[i];
    }
    if(find_if(arr.begin(), arr.end(),[](ll x){return x<=0 || x>1'000'000'000;})==arr.end()) {
        for (auto k: arr)cout << k << ' ';
    }
    else cout<<"-1\n";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    int tc = 1;
//    cin >> tc;
    while (tc--) solve();
}