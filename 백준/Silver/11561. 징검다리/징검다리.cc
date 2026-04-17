#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, m;
    cin >> n;
    m = sqrt(2 * n);
    if(m * (m - 1) <= 2 * n && 2 * n < m * (m + 1))cout << m - 1 << "\n";
    else if(m * (m + 1) <= 2 * n && 2 * n < (m + 1) * (m + 2))cout << m << "\n";
    else cout << m + 1 << "\n";
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