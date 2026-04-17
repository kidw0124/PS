#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll i,j;
    ll n,m,r;
    cin>>n;
    set<ll>st;
    for(i=1;i*i<=n+1;i++){
        if((n+1)%i==0)st.insert(i),st.insert((n+1)/i);
    }
    for(auto k:st)if(k<=n)cout<<k<<' ';
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