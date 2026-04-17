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
    ll n,m;
    cin>>n>>m;
    vector<set<ll>>st(n);
    set<ll>rem;
    vector<ll>rorg,org(n);
    for(i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        x--,y--;
        if(x>y) swap(x,y);
        st[x].insert(y);
        st[y].insert(x);
    }
    for(i=0;i<n;i++){
        rem.insert(i);
    }
    for(i=1;i<=n;i++){
        for(auto x:rem){
            if(st[x].empty()||*st[x].rbegin()<x){
                rorg.push_back(x);
                rem.erase(x);
                for(auto y:st[x]){
                    st[y].erase(x);
                }
                org[x]=i;
                break;
            }
        }
    }
    ll ans=0;
    vector<ll>dp(n);
#ifdef kidw0124
    for(auto x:org){
        cout<<x<<" ";
    }
    cout<<endl;
#endif
    for(i=0;i<n;i++){
        if(i==0||*min_element(org.begin(),org.begin()+i)>org[i]){
            dp[i]=1;
        }
        else{
            for(j=0;j<i;j++){
                if(org[j]<org[i]){
                    if(find_if(org.begin()+j,org.begin()+i,[&](ll x){return x>org[j]&&x<org[i];})==org.begin()+i){
                        dp[i]+=dp[j];
                    }
                }
            }
        }
        if(i==n-1||*max_element(org.begin()+i,org.end())==org[i]){
            ans+=dp[i];
        }
    }
#ifdef kidw0124
    for(auto x:dp){
        cout<<x<<" ";
    }
    cout<<endl;
#endif
    cout<<ans<<endl;


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
