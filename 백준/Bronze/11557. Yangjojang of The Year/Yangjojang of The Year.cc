#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, i;
    cin >> n;
    vector<pair<ll, string>> a(n);
    for(i = 0; i < n; i++)cin >> a[i].second >> a[i].first;
    sort(a.begin(), a.end());
    cout << a[n - 1].second << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while(t--)solve();

    return 0;
}