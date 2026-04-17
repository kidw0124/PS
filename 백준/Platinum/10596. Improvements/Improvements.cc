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
    vector<ll>arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<ll>tmp({0});
    vector<ll>dp(n);
    for(i=0;i<n;i++){
        if(tmp.back()<arr[i]){
            tmp.push_back(arr[i]);
        }
        else{
            tmp[lower_bound(tmp.begin(),tmp.end(),arr[i])-tmp.begin()]=arr[i];
        }
        dp[i]= lower_bound(tmp.begin(),tmp.end(),arr[i])-tmp.begin();
    }
    tmp={INT_MIN};
    for(i=0;i<n;i++) {
        if (tmp.back() < -arr[i]) {
            tmp.push_back(-arr[i]);
        } else {
            tmp[lower_bound(tmp.begin(), tmp.end(), -arr[i]) - tmp.begin()] = -arr[i];
        }
        dp[i] += lower_bound(tmp.begin(), tmp.end(), -arr[i]) - tmp.begin();
    }
    cout<<*max_element(dp.begin(),dp.end())-1<<endl;
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
