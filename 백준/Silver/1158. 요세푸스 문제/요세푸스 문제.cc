#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
//using namespace __gnu_pbds;
using ll = int;
using LL = __int128;
using ld = long double;
using pll = pair<LL, LL>;
using tlll = tuple<ll, ll, ll>;

#define debug if constexpr (xdebug) cout << "[DEBUG] "

#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#include <ext/rope>
using namespace __gnu_cxx;

void solve(ll testcase){
    ll i,j;
    ll n,k;
    cin>>n>>k;
    rope<ll>rpe,tmp;
    for(i=0;i<n;i++)rpe.append(i+1);
//    cout<<rpe.size()<<'\n';
    cout<<"<";
    ll idx=0;
    k--;
    while(n) {
        idx = (idx + k) % n;
        cout<<rpe[idx];
        rpe.erase(idx,1);
        if(--n)cout << ", ";
    }
    cout<<">\n";
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
#ifdef kidw0124
    clock_t en = clock();
    cout << "Time: " << (double)(en - st) / CLOCKS_PER_SEC << "s\n";
#endif
    return 0;
}
