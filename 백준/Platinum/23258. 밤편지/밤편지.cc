#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

vector<vector<pll>>roads;
int brr[305][305];
int dp[305][305][305];
int n,q;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i,j,k,l;
    cin>>n>>q;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i!=j){
                for(k=0;k<=n;k++){
                    dp[i][j][k]=2e8;
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>brr[i][j];
            if(brr[i][j]){
                dp[i][j][0]=brr[i][j];
            }
        }
    }
                for(k=1;k<=n;k++){
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i!=j){
                    dp[i][j][k]=min(dp[i][j][k-1],dp[i][k][k-1]+dp[k][j][k-1]);
                }
            }
        }
    }
    //cout<<dp[1][2][1]<<'\n';
//    for(k=0;k<=n;k++){
//        cout<<'\n'<<k<<'\n';
//        for(i=1;i<=n;i++){
//            for(j=1;j<=n;j++){
//                cout<<dp[i][j][k]<<' ';
//            }
//            cout<<'\n';
//        }
//    }
    for(i=0;i<q;i++){
        ll s,e,c;
        cin>>c>>s>>e;
        cout<<(dp[s][e][c-1]+1)%((int)2e8+1)-1<<'\n';
    }
    return 0;
}
