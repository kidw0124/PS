#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll i,j;
    ll n,m,r;
    string str,ans;
    cin>>n>>str;
    stack<ll>stk;
    for(i=0;i<n;i++){
        if(str[i]=='A')ans+='A';
        else{
            ll cnt=0;
            for(j=(ll)ans.size()-2;j>=0;j-=2){
                if(ans[j]=='A'&&ans[j+1]=='B'){
                    ans.pop_back();
                    ans.pop_back();
                    cnt++;
                }
                else break;
            }
            ans+='B';
            for(j=0;j<cnt;j++)ans+='A';
        }
    }
    cout<<ans<<'\n';
}

int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
}