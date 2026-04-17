#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;

constexpr ll INF=1e18;

void solve() {
    ll i,j;
    ll n,m;
    cin>>m;
    vector<vector<ll>>arr(m);
    vector<pll>imb(m);
    for(i=0;i<m;i++){
        cin>>n;
        vector<ll>rarr(n+1);
        arr[i].resize(n);
        for(j=0;j<n;j++){
            cin>>arr[i][j];
            rarr[arr[i][j]]=j;
        }
        imb[i]={abs(rarr[1]-(n-1-rarr[1])),i};
        if(imb[i].first<50){
            cout<<"Bob\n";
        }
        else{
            cout<<"Alice\n";
        }
        cout.flush();
    }
}

int main() {
//#ifdef ONLINE_JUDGE
//    cin.tie(0)->sync_with_stdio(0);
//#else
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
    int tc = 1;
//    cin >> tc;
    while (tc--) solve();
}