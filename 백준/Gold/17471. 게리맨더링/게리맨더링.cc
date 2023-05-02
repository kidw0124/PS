#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef __float128 LD;
typedef __int128_t LL;
typedef __uint128_t ULL;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()

void setup(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

ll n;

void solve(){
    ll i,j,k;
    ll n,m;
    cin>>n;
    ll ans=INT_MAX;
    vector<vector<ll>>edge(n+1);
    vector<ll>arr(n+1);
    for(i=1;i<=n;i++)cin>>arr[i];
    for(i=1;i<=n;i++){
        cin>>m;
        edge[i].resize(m);
        for(j=0;j<m;j++){
            cin>>edge[i][j];
        }
    }
    for(i=1;i+1<(1<<n);i++){
        vector<ll>group_a,group_b,group(n+1);
        ll ga=0,gb=0;
        for(j=0;j<n;j++){
            if(i&(1<<j))group_a.push_back(j+1),group[j+1]=1,ga+=arr[j+1];
            else group_b.push_back(j+1),gb+=arr[j+1];
        }
        vector<bool>vis(n+1);
        stack<ll>stk;
        stk.push(group_a[0]);
        vis[group_a[0]]=vis[group_b[0]]=1;
        while(!stk.empty()){
            ll now=stk.top();
            stk.pop();
            for(auto k:edge[now]){
                if(!vis[k]&&group[k]){
                    vis[k]=1;
                    stk.push(k);
                }
            }
        }
        stk.push(group_b[0]);
        while(!stk.empty()){
            ll now=stk.top();
            stk.pop();
            for(auto k:edge[now]){
                if(!vis[k]&&!group[k]){
                    vis[k]=1;
                    stk.push(k);
                }
            }
        }
        if(count(all(vis),true)==n){
            ans=min(ans,abs(ga-gb));
        }
    }
    cout<<(ans==INT_MAX?-1:ans);
}

int main() {
    setup();
    ll t=1;
    //cin>>t;
    for(ll testcase=1;testcase<=t;testcase++) {
        solve();
    }
    return 0;
}
