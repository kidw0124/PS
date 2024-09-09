#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, m;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  cin >> n >> m;
  ll ans = m;
  for (int i = 2; i * i <= m; i++) {
    if (m % i == 0) {
      ans -= ans / i;
      while (m % i == 0) m /= i;
    }
  }
  if (m > 1) ans -= ans / m;
  cout<<ans<<'\n';
}
