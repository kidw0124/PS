#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    ll n,sum=0;
    cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    ll m=*max_element(arr.begin(), arr.end());
    cout<<min(sum-m,sum/3);
}