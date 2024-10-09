#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pll = pair<ll, ll>;

#define debug if constexpr (xdebug) cout << "[DEBUG] "

#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif

void solve(ll testcase){
    int i,j;
    int n,m,q;
    cin >> n >> m >> q;
    vector<unordered_set<int>>s(m+1),rs(n+1);
    unordered_set<int>over;
    vector<ll>ans(n+1),pfs(m+1);
    ll thres=200;
    for(i=1;i<=q;i++){
        ll type;
        ll x,y;
        cin >> type >> x;
        switch (type) {
            case 1:
                cin >> y;
                if(s[x].find(y) != s[x].end()){
                    ans[y]+=pfs[x];
                    s[x].erase(y);
                    rs[y].erase(x);
                    if(s[x].size()<thres){
                        over.erase(x);
                        for(auto part:s[x]){
                            ans[part]+=pfs[x];
                        }
                        pfs[x]=0;
                    }
                }
                else{
                    rs[y].insert(x);
                    s[x].insert(y);
                    if(s[x].size()>=thres)over.insert(x),ans[y]-=pfs[x];
                }
                break;
            case 2:
                cin>>y;
                if(s[x].size() < thres){
                    for(auto part:s[x]){
                        ans[part]+=y;
                    }
                }
                else pfs[x]+=y;
                break;
            case 3:
                ll tmp=0;
                for(auto cont:over){
                    if(rs[x].find(cont) != rs[x].end()){
                        tmp+=pfs[cont];
                    }
                }
                cout<<ans[x]+tmp<<'\n';
                break;
        }


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
