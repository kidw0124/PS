#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, t,m,s,e;
vector<vector<pair<ll,ll>>>edge;
vector<bool>chk;
vector<ll>ans;
ll dp[10000+5][1005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j,k;
    cin>>n>>t>>m>>s>>e;
    for(i=0;i<10000+5;i++){
        for(j=0;j<1005;j++){
            dp[i][j]=INT_MAX;
        }
    }
    dp[s][0]=0;
    for(ll tc=1;tc<=t;tc++){
        for(j=0;j<n;j++){
            dp[j][tc]=dp[j][tc-1];
        }
        for(i=0;i<m;i++){
            ll a,b,c;
            cin>>a>>b>>c;
            dp[a][tc]=min(dp[a][tc],dp[b][tc-1]+c);
            dp[b][tc]=min(dp[b][tc],dp[a][tc-1]+c);
        }
    }
    cout<<(dp[e][t]==INT_MAX?-1:dp[e][t]);
    return 0;
}