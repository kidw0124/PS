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
    int n;
    cin >> n;
    unordered_map<string, int> mp;
    map<int,vector<string>>vct;
    for(i=0;i<n;i++){
        cin>>j>>j;
        while(j--){
            string s;
            cin >> s;
            mp[s]++;
        }
    }
    for(auto &x:mp){
        vct[x.second].push_back(x.first);
    }
    if(vct.rbegin()->second.size() == 1){
        cout << vct.rbegin()->second[0] << endl;
    }
    else{
        cout<<-1<<endl;
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
