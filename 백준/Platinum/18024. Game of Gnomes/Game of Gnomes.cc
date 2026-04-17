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
    ll i,j;
    ll n,m,k;
    cin >> n >> m >> k;
    ll ans=0,nk=n/k;
    for(i=max(0ll,nk-(ll)1e7);i<=nk;i++){
        ll q=(n-k*i)/m/k;
        ll grp=i+q;
        ll tmp=k*grp*(grp+1)/2+(n-k*grp)*grp;
        ll rem=(n-k*grp)%m;
        ll r=(n-k*grp)/m;
        tmp+=rem*(rem+1)/2*(r+1)+rem*r*(m-rem);
        tmp+=(m-rem)*(m-rem+1)/2*r;
        ans=max(ans,tmp);
    }
    cout << ans << '\n';
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
