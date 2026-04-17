#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#ifdef ONLINE_JUDGE
constexpr bool XDEBUG = false;
#else
constexpr bool XDEBUG = true;
#endif


void setup(){
    if(XDEBUG){
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
    else{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void preprocess(){
    ll i,j,k;
}


void solve(ll testcase){
    ll i,j,k;
    ll n;
    cin>>n;
    vector<ll>ans;
    vector<ll>arr(n),sum(n+1),mini(n+1,INT_MAX);
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=n-1;i>0;i--){
        sum[i]=sum[i+1]+arr[i];
        mini[i]=min(mini[i+1],arr[i]);
        if(i==n-1)continue;
        if(ans.empty()){
            ans.push_back(i);
        }
        else if((sum[i]-mini[i])*(n-ans[0]-1)==(sum[ans[0]]-mini[ans[0]])*(n-i-1)){
            ans.push_back(i);
        }
        else if((sum[i]-mini[i])*(n-ans[0]-1)>(sum[ans[0]]-mini[ans[0]])*(n-i-1)){
            ans.clear();
            ans.push_back(i);
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto k:ans){
        cout<<k<<'\n';
    }
}

int main(){
    setup();
    preprocess();
    ll t=1;
//    cin>>t;
    for(ll i=0;i<t;i++){
        solve(i+1);
    }
}