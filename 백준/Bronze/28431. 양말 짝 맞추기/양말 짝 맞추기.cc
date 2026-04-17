#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#ifdef DWOO
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (ddebug) cout << "[DEBUG] " << #x << " == " << x << '\n';

int main(){
#ifdef DWOO
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#endif
    ll i,j;
    ll n,ans=0;
    n=5;
    vector<ll>arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i];
        ans^=arr[i];
    }
    cout<<ans;
}