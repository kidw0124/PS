#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
string s1,s2;
int dp[1001][1001]={0};
pii dp3[1001][1001];
bool dp2[1001][1001]={0};
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>s1>>s2;
    int l1=s1.size(),l2=s2.size();
    int i,j;
    for(i=1;i<=l1;i++){
        for(j=1;j<=l2;j++){
            if(s1[i-1]!=s2[j-1]){
                if(dp[i-1][j]>dp[i][j-1])dp[i][j]=dp[i-1][j],dp3[i][j]={i-1,j},dp2[i][j]=0;
                else dp[i][j]=dp[i][j-1],dp3[i][j]={i,j-1},dp2[i][j]=0;
            }
            else dp[i][j]=dp[i-1][j-1]+1,dp3[i][j]={i-1,j-1},dp2[i][j]=1;
        }
    }
    pii x={l1,l2};
    string s;
    while(x.first*x.second){
        if(dp2[x.first][x.second])s+=s1[x.first-1];
        x=dp3[x.first][x.second];
    }
    cout<<dp[l1][l2];
    reverse(s.begin(),s.end());
    cout<<'\n'<<s;
}
