#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

#ifdef ONLINE_JUDGE
constexpr bool ddebug=false;
#else
constexpr bool ddebug=true;
#endif

void solve(){
    ll i,j,k;
    multiset<ll>ms[10];
    ll n,m;
    cin>>n>>k;
    ll ans=0;
    vector<pll>arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    for(i=0;i<k;i++){
        ms[arr[i].first].insert(arr[i].second);
    }
    auto check=[&](){
        ll x=0;
        for(ll i=1;i<=9;i++){
            if(ms[i].size()){
                x+=*ms[i].rbegin();
            }
            else return 0ll;
        }
        return x;
    };
    ans=check();
    for(i=k;i<n;i++){
        ms[arr[i-k].first].erase(ms[arr[i-k].first].find(arr[i-k].second));
        ms[arr[i].first].insert(arr[i].second);
        ans=max(ans,check());
    }
    cout<<ans<<'\n';

}


int main(){
    if(!ddebug){
        ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    }
    else{
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
    ll t=1;
    cin>>t;
    while(t--)solve();
}