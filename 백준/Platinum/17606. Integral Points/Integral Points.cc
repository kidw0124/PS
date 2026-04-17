#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using LL = __int128;
using ld = long double;
using pll = pair<LL, LL>;

#define debug if constexpr (xdebug) cout << "[DEBUG] "

#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif


void solve(ll testcase){
    ll i,j;
    ll n;
    cin>>n;
    vector<pll>arr;
    for(i=4;arr.size()*150<n;i+=2){
        for(j=(((i>>1)&(~1))^1);j>0;j-=2){
            if(gcd(j,i-j)==1){
                arr.push_back({j,i-j});
            }
        }
    }
//    auto r= accumulate(arr.begin(),arr.end(),1ll,[&](ll a,pll b){
//        return lcm(a,(b.first*b.first+b.second*b.second)/2);
//    });
    ll r=6569225;
    cout<<r<<'\n';
    vector<pll>ans;
    for(i=1;i<r && ans.size()<n;i++){
        ll p=i*i;
        LL q=(LL)r*r-p;
        if(p>q)continue;
        ll sq=(ll)sqrt((ld)q);
        if(sq*sq==q){
            ans.push_back({i,sq});
            ans.push_back({i,-sq});
            ans.push_back({-i,sq});
            ans.push_back({-i,-sq});
            ans.push_back({sq,i});
            ans.push_back({sq,-i});
            ans.push_back({-sq,i});
            ans.push_back({-sq,-i});
        }
    }
    for(i=0;i<n;i++){
        cout<<(ll)ans[i].first<<' '<<(ll)ans[i].second<<'\n';
    }


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
//    cin >> t;
    for(int i = 1; i <= t; i++) solve(i);
    clock_t ed = clock();
#ifdef kidw0124
    clock_t en = clock();
    cout << "Time: " << (double)(en - st) / CLOCKS_PER_SEC << "s\n";
#endif
    return 0;
}
