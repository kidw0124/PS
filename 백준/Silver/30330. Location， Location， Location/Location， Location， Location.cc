#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

void solve() {
    ll n, i;
    cin >> n;
    vector<ll> a(n), b(n);
    for(i = 0; i < n; i++)cin >> a[i] >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    cout << a[(n - 1) / 2] << " " << b[(n - 1) / 2];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}