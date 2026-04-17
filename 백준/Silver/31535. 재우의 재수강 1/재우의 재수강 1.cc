#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;
typedef unsigned long long ull;
typedef __float128 LD;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto &x : a)
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "
#ifndef kidw0124
const ll TSIZE = 1 << 20; // always 2^k form && n <= TSIZE
#else
const ll TSIZE = 1 << 3; // always 2^k form && n <= TSIZE
#endif

const ll mod = 1e9+7;

void setup()
{
    if(ddebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    else {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void preprocess() {
    ll i, j;


}

void solve(ll testcase){
    ll w,h;
    ll n,m;
    ll i,j,k;
    cin >> w >> h;
    cin >> n;
    m=1;
    vector<ll>arr(n+1),prr(n+1),drr(m);
    cin>>drr[0];
    for(i=1;i<=n;i++) cin >> arr[i];
    for(i=1;i<=n;i++) cin >> prr[i];
    for(i=0;i<m;i++){
        ll ans = 1e18;
        for(j=1;j<=n;j++){
            ll x = w*prr[j];
            if(arr[j-1] <= drr[i]){
                for(k=1;arr[k]<drr[i];k++){
                    x += (arr[k]-arr[k-1]) * prr[k];
                }
                x += (drr[i]-arr[k-1]) * prr[k];
            }
            else{
                for(k=1;k<j;k++){
                    x += (arr[k]-arr[k-1]) * prr[k];
                }
                for(k=j-1;k-1 >= 0 && arr[k-1]>drr[i];k--){
                    x += (arr[k]-arr[k-1]) * prr[k];
                }
                x += (arr[k]-drr[i]) * prr[k];
            }
            ans = min(ans,x);
        }
        cout << ans << " ";

    }

}


int main()
{
    setup();
    preprocess();
    ll t = 1;
//    cin >> t;
    for (ll testcase = 1; testcase <= t; testcase++)
    {
        solve(testcase);
    }
    return 0;
}
