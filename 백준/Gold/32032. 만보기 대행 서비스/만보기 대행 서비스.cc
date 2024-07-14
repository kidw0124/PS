#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
typedef unsigned long long ull;
using pll = pair<ll,ll>;

void solve()
{
    ll n, m, i, res;
    cin >> n >> m;
    vector<ll> a(n);
    for(i = 0; i < n; i++)cin >> a[i];

    sort(a.begin(), a.end());
    if(a[0] <= 0 && a[n - 1] <= 0)res = -a[0] * 2 + m;
    else if(a[0] >= 0 && a[n - 1] >= 0)res = a[n - 1] * 2 + m;
    else {
        res = -a[0] * 2 + a[n - 1] * 2 + m * 2;
        res = min(res, -a[0] * 4 + a[n - 1] * 2 + m);
        res = min(res, -a[0] * 2 + a[n - 1] * 4 + m);
        if((a[n - 1] - a[0]) * 2 >= m)res = min(res, (a[n - 1] - a[0]) * 4);
        else res = min(res, -a[0] * 2 + a[n - 1] * 2 + m);
    }

    cout << res;
}

int main() {
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    clock_t st=clock();
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    solve();

    return 0;
}