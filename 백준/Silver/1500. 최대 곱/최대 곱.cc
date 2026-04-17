#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

#ifdef kidw0124
constexpr bool ddebug = 1;
#else
constexpr bool ddebug=0;
#endif

void init(){
    if(ddebug){
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
    else{

        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
}

void solve() {
    ll i,j,k;
    ll n,m;
    cin>>n>>m;
    ll ans=1;
    for(i = 0; i < m; i++){
        if(i<(n%m)){
            ans*=((n/m)+1);
        }
        else{
            ans*=(n/m);
        }
    }
    cout<<ans;
}

int main(){
    init();
    solve();

    return 0;
}