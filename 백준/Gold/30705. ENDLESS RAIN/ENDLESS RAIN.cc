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
    ll n,m,ans=0;
    cin>>n>>m;
    vector<pll>arr(m);
    vector<ll>grp(n+1);
    iota(grp.begin(), grp.end(),0);
    function<ll(ll)> _find = [&](ll x){
        if(grp[x]==x)return x;
        else return grp[x]=_find(grp[x]);
    };
    function<void(ll,ll)> _union = [&](ll x,ll y){
        x=_find(x),y=_find(y);
        if(x>y)swap(x,y);
        grp[y]=x;
    };
    ll rem=0;
    for(i=0;i<m;i++){
        cin>>arr[i].first>>arr[i].second;
        rem++;
        ll p=_find(arr[i].second);;
        while(p>arr[i].first){
            if(rem)rem--;
            else ans++;
            _union(p-1,p);
            p=_find(p);
        }
    }
    cout<<ans;
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