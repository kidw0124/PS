#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll,ll>;
using pld = pair<ld,ld>;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif

#define debug if constexpr(ddebug) cout<<"[DEBUG] "

void setup(){
    if(ddebug){
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
    ll i,j;
}
#ifdef kidw0124
ll maxbit=4;
#else
ll maxbit=64;
#endif
void solve(ll testcase){
    ll i, j, k;
    ll n,m;
    cin>>n;
    vector<pll>arr,brr;
    for(i=0;i<maxbit;i++){
        for(j=0;j<i;j++){
            arr.push_back({i*100,j});
        }
        for(j=0;j<maxbit-i;j++){
            for(k=0;k<maxbit-i;k++){
                arr.push_back({i*100+j,k+i});
                if(j+k==maxbit-i-1){
                    brr.push_back({i*100+j,k+i});
                }
            }
        }
    }
    bitset<64>bs(n);
    cout<<arr.size()<<'\n';
    for(auto[a,b]:arr){
        if(a%100==0 && b==0 && bs[maxbit-1-a/100]){
            cout<<a<<' '<<b<<' '<<"1\n";
        }
        else cout<<a<<' '<<b<<' '<<"0\n";
    }
    cout<<brr.size()<<' '<<maxbit-1<<'\n';
    for(auto [a,b]:brr){
        cout<<a<<' '<<b<<'\n';
    }


}

int main(){
    setup();
    preprocess();
    ll t=1;
//    cin>>t;
    for(ll tc=0;tc<t;tc++){
        solve(tc+1);
    }
}