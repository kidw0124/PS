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

ll phi(ll n){
    ll ret = n;
    if(n==1)return 0;
    for(ll i = 2; i*i<=n; i++){
        if(n%i==0){
            ret-=ret/i;
            while(n%i==0)n/=i;
        }
    }
    if(n>1)ret-=ret/n;
    return ret;
}

void solve() {
    ll n, m, k, i, p, q;
    cin>>n;
    if(n==0){
        exit(0);
    }
    cout<<phi(n)<<"\n";
}

int main(){
    init();
    while(true)
    solve();

    return 0;
}