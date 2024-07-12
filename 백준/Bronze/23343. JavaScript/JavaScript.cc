#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using m_os
    =tree<T, null_type,  less_equal<T>,
            rb_tree_tag, tree_order_statistics_node_update>;
using ll = int;
using ld = long double;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
void solve() {
    string str1,str2;
    cin>>str1>>str2;
    for(auto k:str1)if(!isdigit(k)) {
            cout << "NaN";
            return;
        }
    for(auto k:str2)if(!isdigit(k)) {
            cout << "NaN";
            return;
        }
    cout<<stoll(str1)-stoll(str2);
}

int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while (t--) solve();
}