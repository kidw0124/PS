#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ll n;
    cin>>n;
    if(n<=5)cout<<"-1\n";
    else{
        if(n==6)cout<<"3\n";
        else cout<<"4\n";
        cout<<1<<' ';
        if(n==6)cout<<"3 ";
        else cout<<"3 "<<n-3<<" ";
        cout<<n-2<<"\n";
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
    cin >> tc;
    while (tc--) solve();
}