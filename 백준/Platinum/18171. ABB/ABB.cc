#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string str;
    cin >> n >> str;
    string tmp = str;
    reverse(tmp.begin(), tmp.end());
    str=tmp+str;
    vector<int> pi(2*n);
    for (int i = 1, j = 0; i < 2*n; i++) {
        if(j>=n) j=pi[j-1];
        while (j && str[i] != str[j]) j = pi[j-1];
        if (str[i] == str[j]) pi[i] = ++j;
    }
    cout<<max(0,n-pi[2*n-1])<<'\n';
}

int main() {
#ifdef kidw0124
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    int t = 1;
    //cin >> t;
    while (t--) solve();
}