#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

void preprocess() {
    ;
}

void solve() {
    ll n, m, i, p, q, r, tmp;
    cin >> n >> m;
    vector<ll> a(n - 1), sum(n + 2);
    for(i = 0; i < n - 1; i++)cin >> a[i];
    for(i = 0; i < m; i++) {
        cin >> p >> q >> r;
        sum[p]+=r;
        sum[q]-=r;
    }
    ll ans=0;
    for(i = 0; i < n - 1; i++) {
        ans+=sum[i+1];
        q=ans/a[i],r=ans%a[i];
        cout<<(q+1)*(q+1)*(r)+q*q*(a[i]-r)<<'\n';
    }

}

int main() {
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    preprocess();
    ll t=1;
//    cin>>t;
    while(t--)solve();
}