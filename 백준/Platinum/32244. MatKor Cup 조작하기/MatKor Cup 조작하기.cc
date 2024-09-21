#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "

constexpr ll MOD = 1e9+9;

void solve(){
    int i,j,k;
    ll n,ans=0;
    cin>>n;
    vector<string>vct(n);
    vector<vector<ll>>arr(n,vector<ll>(n));
    vector<ll>row(n),col(n);
    for(i=0;i<n;i++)cin>>vct[i];
    for(i=0;i<n;i++)for(j=0;j<n;j++){
        vct[i][j]-='1';
    }
    auto do_func=[&arr,&n](ll x, ll y){
        arr[x][y]++;
        if(n>>1&1){
            arr[x][y]+=n;
        }
    };
    ll tot=0;
    for(i=0;i<n;i++){
        string str;
        cin>>str;
        for(j=0;j<n;j++){
            str[j]-='1';
            vct[i][j]=str[j]-vct[i][j];
            if(vct[i][j]<0)vct[i][j]+=4;
            if(n>>1&1){
                tot+=2*vct[i][j];
                row[i]+=vct[i][j];
                col[j]+=vct[i][j];
                while(vct[i][j]--){
                    do_func(i,j);
                }
            }
            else{
                vct[i][j]=4-vct[i][j];
                tot+=2*vct[i][j];
                row[i]+=vct[i][j];
                col[j]+=vct[i][j];
                while(vct[i][j]--){
                    do_func(i,j);
                }
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ans+=(arr[i][j]+row[i]+col[j]+tot)%4;
        }
    }
    cout<<ans<<'\n';

}

int main() {
#ifdef kidw0124
    freopen("input.txt","r",stdin);
//    freopen("xor10.in","r",stdin);
    freopen("output.txt","w",stdout);
    clock_t st=clock();
#else
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#endif
    int t=1;
//    cin>>t;
    while(t--)solve();
#ifdef kidw0124
    debug<<clock()-st<<"ms\n";
#endif
}