#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#ifdef DWOO
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (ddebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
void setup(){
#ifdef DWOO
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#endif
}
void preprocess(){

}

void solve(ll testcase){
    ll n,i,j;
    char t;
    tuple<ll,ll,ll>base;
    cin>>get<0>(base)>>t>>get<1>(base)>>t>>get<2>(base);
    cin>>n;
    vector<tuple<ll,ll,ll>>arr(n);
    for(auto&[a,b,c]:arr)cin>>a>>t>>b>>t>>c;
    cout<<count_if(arr.begin(),arr.end(),[&base](auto k){
        return base<=k;
    });
}

int main(){
    setup();
    preprocess();
    ll t=1;
//    cin>>t;
    for(ll testcase = 1; testcase<=t;testcase++)solve(testcase);
}