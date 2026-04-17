#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "
#define debugv(x) if constexpr(ddebug){cout<<"[DEBUG] "<<#x<<" : "<<x<<'\n';}
#define debugc(c) if constexpr(ddebug) {cout << "[DEBUG] "<<#c<<" : "; for(auto &x : c) cout << x << ", "; cout << '\n';}


void setup() {
    if(ddebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    else {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    }
}

void preprocess(){
    ll i,j;

}

void solve(ll testcase) {
    ll i,j,k;
    ll n,m;
    cin>>n>>m;
    vector<string>arr(n),brr(n);
    vector<vector<bool>>vis(n,vector<bool>(m));
    for(auto &k:arr)cin>>k;
    for(auto &k:brr)cin>>k;
    function<bool(ll,ll)> dfs = [&](ll x, ll y){
        if(brr[x][y]!=brr[i][j])return false;
        else{
            ll dx[4]={0,1,-1,0},dy[4]={1,0,0,-1};
            for(ll i=0;i<4;i++){
                if(x+dx[i]<0 || y+dy[i]<0 || x+dx[i]>=n || y+dy[i]>=n)continue;
                else if(vis[x+dx[i]][y+dy[i]]||arr[x+dx[i]][y+dy[i]]!=arr[x][y]) continue;
                else {
                    vis[x+dx[i]][y+dy[i]]=1;
                    bool b=dfs(x+dx[i],y+dy[i]);
                    if(!b)return false;
                }
            }
        }
        return true;
    };
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(!vis[i][j]){
                vis[i][j]=1;
                if(!dfs(i,j)){
                    cout<<"NO\n";
                    return;
                }
            }
        }
    }
    cout<<"YES\n";
}

int main() {
    setup();
    preprocess();
    ll t = 1;
//    cin >> t;
    for(ll i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}