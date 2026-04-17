#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
using namespace __gnu_pbds;
using ll = int;
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
    constexpr ll MAXN = 1'000'000+5;
    vector<bool>is_prime(MAXN, true);
    vector<vector<ll>> invfactors(MAXN);
    vector<ll>offset(MAXN,0);
    vector<vector<ll>> factors(MAXN);
    is_prime[0] = is_prime[1] = false;
    for(i = 2; i < MAXN; i++){
        if(is_prime[i]) {
            for(j=i; j < MAXN; j+=i){
                is_prime[j] = false;
                factors[j].push_back(i);
                invfactors[i].push_back(j);
            }
        }
    }
    for(i=1;i<MAXN;i++){
        factors[1].push_back(i);
    }
    vector<ll>ans(MAXN,0);
    ll n;
    ll now=1,cnt=1;
    ans[1]=1;
    while(cin>>n,n){
        while(!ans[n]){
            ll tmp=MAXN;
            for(auto &p: factors[now]){
                while(offset[p]<invfactors[p].size()){
                    ll q=invfactors[p][offset[p]];
                    if(ans[q]==0){
                        tmp=min(tmp,q);
                        break;
                    }
                    offset[p]++;
                }
            }
            now = tmp;
            ans[now] = ++cnt;
        }
        cout<<"The number "<<n<<" appears in location "<<ans[n]<<".\n";
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
    // cin >> t;
    for(int i = 1; i <= t; i++) solve(i);
    clock_t ed = clock();
#ifdef kidw0124
    clock_t en = clock();
    cout << "Time: " << (double)(en - st) / CLOCKS_PER_SEC << "s\n";
#endif
    return 0;
}
