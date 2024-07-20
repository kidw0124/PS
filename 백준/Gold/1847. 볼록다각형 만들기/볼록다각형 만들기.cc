#include<bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll mod=1e9+7;

void solve(){
    ll i,j;
    ll n;
    cin>>n;
    if(!n)return;
    vector<vector<ll>>arr(n);
    assert(n>=3);
    for(i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        if(a>b)swap(a,b);
        arr[i].push_back(b-1);
        arr[i].push_back(a-1);
    }
    if(find_if(arr.begin(),arr.end(),[](vector<ll>&a){
        return a.size()!=2;
    })!=arr.end()){
        cout<<"-1\n";
        return;
    }
    vector<ll>brr(n);
    auto lis=[&](){
        vector<ll>dp(n,1e9);
        for(int i=0;i<n;i++){
            auto it=lower_bound(dp.begin(),dp.end(),brr[i]);
            *it=brr[i];
        }
        return lower_bound(dp.begin(),dp.end(),1e9)-dp.begin();
    };
    ll ans=n;
    for(i=0;i<n;i++){
        vector<bool>vis(n);
        ll now=i;
        for(j=0;j<n;j++){
            brr[j]=now;
            vis[now]=1;
            if(!vis[arr[now][0]]){
                now=arr[now][0];
            }
            else if(!vis[arr[now][1]]){
                now=arr[now][1];
            }
            else{
                break;
            }
        }
        if(j<n-1){
            cout<<"-1\n";
            return;
        }
//        for(auto k:brr)cout<<k<<' ';cout<<'\n';
        ans=min(ans,n-lis());
        reverse(brr.begin(),brr.end());
        ans=min(ans,n-lis());
    }
    cout<<ans<<'\n';
}

int main(){
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    ll t=1;
//    cin>>t;
    while(t--)solve();
}
