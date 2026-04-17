#include<bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {

    string str;

    cin>>str;

    ll n=str.size()-1;

    while(n>0&&str[n-1]<str[n])n--;

    cout<<n<<'\n';

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