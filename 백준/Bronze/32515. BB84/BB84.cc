#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;

void solve() {
    ll i,j;
    ll n;
    string str1,str2,str3,str4,ans;
    cin>>n>>str1>>str2>>str3>>str4;
    for(i=0;i<n;i++){
        if(str1[i]==str3[i]){
            if(str2[i]==str4[i])ans+=str2[i];
            else{
                cout<<"htg!\n";
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