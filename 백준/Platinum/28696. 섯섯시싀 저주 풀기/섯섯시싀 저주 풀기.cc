#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;

#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "

const ll mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll i,j,k;
    ll n,r2;
    cin>>n>>r2;
    vector<pll> arr(n);
    vector<pld> arr2(n);
    for(i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
        arr2[i] = {arr[i].first < 0? -sqrt(-arr[i].first) : sqrt(arr[i].first),
                    arr[i].second < 0? -sqrt(-arr[i].second) : sqrt(arr[i].second)};
    }
    ld ans = 0;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            ll xsys = abs(arr[i].first) + abs(arr[j].first)
                    + abs(arr[i].second) + abs(arr[j].second);
            ld f =(arr2[i].first - arr2[j].first)*(arr2[i].first - arr2[j].first)
                    + (arr2[i].second - arr2[j].second)*(arr2[i].second - arr2[j].second);
            ans += log(f)/2;
        }
    }
    ans *= n-2;
    cout<<fixed<<setprecision(100);
    debug<<ans<<' '<<exp(ans)<<'\n';
    ll nc3 = n*(n-1)*(n-2)/6;
    ans -= nc3 * log((ld)(r2+r2));
    debug<<ans<<' '<<exp(ans)<<'\n';
    cout<<fixed<<setprecision(100)<<ans<<'\n';
}