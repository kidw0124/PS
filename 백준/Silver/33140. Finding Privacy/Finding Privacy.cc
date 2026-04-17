#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, m, minimum, maximum, i, cnt;
    cin >> n >> m;
    minimum = (m + 2) / 3;
    maximum = (m + 1) / 2;
    if(minimum <= n && n <= maximum) {
        string res;
        for(i = 1; i < n; i++)res += "X-";
        res += "X";
        cnt = m - res.size();
        if(cnt) {
            res += "-";
            cnt--;
        }
        for(i = 0; i < res.size(); i++) {
            if(res[i] == 'X') {
                if(cnt) {
                    cout << "-";
                    cnt--;
                }
            }
            cout << res[i];
        }
    }
    else cout << "*";
}

int main(){
#ifdef kidw0124
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    solve();
    return 0;
}