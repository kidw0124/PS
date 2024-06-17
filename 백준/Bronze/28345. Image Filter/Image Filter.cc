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
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>arr(n,vector<ll>(m));
    for(i=0;i<n;i++)for(j=0;j<m;j++)cin>>arr[i][j];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            ll nowfilter=0;
            ll nowvalue=arr[i][j];
            ll a=j>0?arr[i][j-1]:0;
            ll b=i>0?arr[i-1][j]:0;
            ll c=(i>0&&j>0)?arr[i-1][j-1]:0;
            if(abs(arr[i][j]-a)<abs(nowvalue)){
                nowfilter=1;
                nowvalue=arr[i][j]-a;
            }
            if(abs(arr[i][j]-b)<abs(nowvalue)){
                nowfilter=2;
                nowvalue=arr[i][j]-b;
            }
            if(abs(arr[i][j]-(a+b)/2)<abs(nowvalue)){
                nowfilter=3;
                nowvalue=arr[i][j]-(a+b)/2;
            }
            if(abs(arr[i][j]-(a+b-c))<abs(nowvalue)){
                nowfilter=4;
                nowvalue=arr[i][j]-(a+b-c);
            }
            cout<<nowfilter<<' '<<nowvalue<<' ';
        }
        cout<<'\n';
    }
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