#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using ll = long long;
using LL = __int128;
using pll = pair<ll, ll>;
using ld = long double;
using pld = pair<ld, ld>;

void solve() {
    ll i,j;
    ll n;
    cin>>n;
    vector<pld> arr(n);
    for(i=0;i<n;i++)cin>>arr[i].first>>arr[i].second;
    ld ans=0;
    for(i=0;i<n;i++){
        ans+=arr[i].first*arr[(i+1)%n].second;
        ans-=arr[i].second*arr[(i+1)%n].first;
    }
    cout<<fixed<<setprecision(15)<<abs(ans/2) * (3 - acos(-1) / sqrt(3)) / 9;

}

int main() {
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    clock_t beg = clock();
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
//    preprocess();
    ll t=1;
//    cin>>t;
    while(t--)solve();
#ifdef kidw0124
    cout<<clock()-beg<<"ms\n";
#endif
}