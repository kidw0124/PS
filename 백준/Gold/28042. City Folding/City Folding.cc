#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

void solve() {
    ll i,j;
    ll n,p,h;
    cin>>n>>p>>h;
    p--,h--;
    ll now=(1ll<<n)>>1;
    vector<bool>arr(n);
    for(i=0;i<n;i++){
        if(h/now){
            arr[i]=1;
            h%=now;
            h=(now-1-h);
        }
        now>>=1;
    }
    reverse(arr.begin(), arr.end());
    now=(1ll<<n)>>1;
    for(i=0;i<n;i++){
        if(p/now==arr[i]){
            cout<<'R';
            if(p/now) {
                p %= now;
                p = (now - 1 - p);
            }
        }
        else{
            cout<<'L';
            if(p/now){
                p%=now;
            }
            else{
                p=(now-1-p);
            }
        }
        now>>=1;
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