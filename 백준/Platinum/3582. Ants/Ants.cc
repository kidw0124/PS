#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

#define debug if constexpr (xdebug) cout << "[DEBUG] "

#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif

void solve(ll testcase){
    int i,j;
    ll n;
    cin>>n;
    vector<pll>arr(n),brr(n);
    vector<ll>ans(n,-1);
    for(i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    for(i=0;i<n;i++){
        cin>>brr[i].first>>brr[i].second;
    }
    auto dist=[](pll a,pll b){
        return sqrt((ld)(a.first-b.first)*(a.first-b.first)+(ld)(a.second-b.second)*(a.second-b.second));
    };
    iota(ans.begin(),ans.end(),0);
    bool flag=true;
    while(flag){
        flag=false;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(dist(arr[i],brr[ans[i]])+dist(arr[j],brr[ans[j]])>dist(arr[i],brr[ans[j]])+dist(arr[j],brr[ans[i]])){
                    swap(ans[i],ans[j]);
                    flag=true;
                }
            }
        }
    }
    for(auto x:ans)cout<<x+1<<'\n';
}

int main(){

#ifdef kidw0124
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    clock_t st = clock();
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) solve(i);
    clock_t ed = clock();
#ifdef kidw0124
    clock_t en = clock();
    cout << "Time: " << (double)(en - st) / CLOCKS_PER_SEC << "s\n";
#endif
    return 0;
}
