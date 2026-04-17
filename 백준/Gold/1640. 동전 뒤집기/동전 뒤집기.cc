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
    ll n,m;
    cin>>n>>m;
    vector<bitset<1000>>arr(n);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            char c;
            cin>>c;
            arr[i][j]=c-'0';
        }
    }
    ll x=0,y=0;
    for(i=0;i<n;i++){
        x+=arr[i].count()&1;
    }
    for(j=0;j<m;j++){
        ll a=0;
        for(i=0;i<n;i++){
            a^=arr[i][j];
        }
        y+=a;
    }
    if(x&1){
        cout<<min(x+m-y,n-x+y);
    }
    else{
        cout<<min(x+y,n-x+m-y);
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