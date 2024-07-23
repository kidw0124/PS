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
    ll n;
    cin>>n;
    vector<vector<ll>>arr(n,vector<ll>(6));
    ll cnt[7][7][7][7][7][7]={},dp[7][7][7][7][7][7]={};
    for(i=0;i<n;i++){
        for(j=0;j<6;j++){
            cin>>arr[i][j];
        }
        cnt[arr[i][0]][arr[i][1]][arr[i][2]][arr[i][3]][arr[i][4]][arr[i][5]]++;
    }
    for(int i1=0;i1<7;i1++){
        for(int i2=0;i2<7;i2++){
            for(int i3=0;i3<7;i3++){
                for(int i4=0;i4<7;i4++){
                    for(int i5=0;i5<7;i5++){
                        for(int i6=0;i6<7;i6++){
                            for(int j1=i1;j1<7;j1++){
                                for(int j2=i2;j2<7;j2++){
                                    for(int j3=i3;j3<7;j3++){
                                        for(int j4=i4;j4<7;j4++){
                                            for(int j5=i5;j5<7;j5++){
                                                for(int j6=i6;j6<7;j6++){
                                                    dp[i1][i2][i3][i4][i5][i6]+=cnt[j1][j2][j3][j4][j5][j6];
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    ll ans=n;
    vector<ll>anss;
    for(i=0;i<n;i++){
        ll now=dp[arr[i][0]][arr[i][1]][arr[i][2]][arr[i][3]][arr[i][4]][arr[i][5]];
        if(now<ans)ans=now,anss.clear();
        if(now==ans)anss.push_back(i+1);
    }
    cout<<anss.size()<<' '<<n-ans<<'\n';
    for(auto x:anss){
        cout<<x<<' ';
    }
}

int main() {
#ifdef kidw0124
    freopen("input.txt","r",stdin);
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