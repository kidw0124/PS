#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll i,j;
    ll n,q;
    cin>>n>>q;
    vector<ll>cows(n);
    vector<ll> one(n+1),two(n+1),three(n+1);
    for(i=0;i<n;i++)cin>>cows[i];
    for(i=0;i<n;i++){
        one[i+1]=one[i];
        two[i+1]=two[i];
        three[i+1]=three[i];
        if(cows[i]==1)one[i+1]++;
        else if(cows[i]==2)two[i+1]++;
        else three[i+1]++;
    }
    while(q--){
        ll l,r;
        cin>>l>>r;
        cout<<one[r]-one[l-1]<<" "
            <<two[r]-two[l-1]<<" "
            <<three[r]-three[l-1]<<"\n";
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