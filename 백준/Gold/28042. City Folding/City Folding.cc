#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

void solve() {
    ll i,j;
    ll n,p,h;
    cin>>n>>p>>h;
    p--,h--;
    vector<ll>arr(n);
    for(i=0;i<n;i++){
        j=(1LL<<(n-i-1));
        if(h&j){
            arr[i]=1LL<<i;
            h=(j<<1)-1-h;
        }
    }
    reverse(arr.begin(), arr.end());
    for(i=0;i<n;i++){
        j=(1LL<<(n-i-1));
        if((p&j)==arr[i]){
            cout<<'R';
            if(p&j) {
                p=(j<<1)-1-p;
            }
        }
        else{
            cout<<'L';
            if(p&j){
                p^=j;
            }
            else{
                p=(j-1-p);
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    int t = 1;
    //cin >> t;
    while (t--) solve();
}