#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll i,j;
    string str;
    cin>>i>>str;
    for(i=0;i<str.size();i++){
        if(islower(str[i]))str[i]= toupper(str[i]);
        else str[i]= tolower(str[i]);
    }
    cout<<str<<'\n';
}

int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
//    cin >> tc;
    while (tc--) solve();
}