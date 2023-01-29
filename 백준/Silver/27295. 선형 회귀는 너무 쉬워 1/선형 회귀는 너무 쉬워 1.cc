#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, b, sx = 0, sy = 0;
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        sx += x;
        sy += y;
    }
    if (sx == 0) {
        cout << "EZPZ\n";
    } else {
        sy -= n * b;
        if (sx < 0) {
            sx = -sx;
            sy = -sy;
        }
        ll g = gcd(sx, abs(sy));
        if (g == sx) {
            cout << sy / g << '\n';
        } else {
            cout << sy / g << '/' << sx / g << '\n';
        }
    }
}