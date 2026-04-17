#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    string s; cin >> s;
    ll sum = 0, cnt = 0;
    for (int i = 0; i < s.size(); i++) if (s[i] == '1') cnt++;
    for (int i = 0; i < s.size(); i++) if (s[i] == '1') sum += (s.size() - cnt--) - i;
    cout << (sum % 3 ? "Alice" : "Bob") << '\n';
}