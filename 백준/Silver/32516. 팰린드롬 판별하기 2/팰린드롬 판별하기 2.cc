#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;

void solve() {
    ll i,j;
    ll n;
    string str;
    cin>>n>>str;
    string rstr=str;
    reverse(str.begin(), str.end());
    ll ans=0;
    for(i=0;i<n/2;i++){
        if(str[i]==rstr[i]){
            if(str[i]=='?')ans+=26;
        }
        else{
            if(str[i]=='?' || rstr[i]=='?')ans++;
            else{
                cout<<"0\n";
                return;
            }
        }
    }
    cout<<ans<<'\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    int tc = 1;
//    cin >> tc;
    while (tc--) solve();
}