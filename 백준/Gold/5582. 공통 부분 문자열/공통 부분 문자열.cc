#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1,s2;
int dp[5001][5001]={0};
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>s1>>s2;
    int l1=s1.size(),l2=s2.size();
    int i,j;
    ll ans=0;
    for(i=1;i<=l1;i++){
        for(j=1;j<=l2;j++){
            dp[i][j]=(s1[i-1]-s2[j-1])?0:dp[i-1][j-1]+1;
            ans=max(ans,(ll)dp[i][j]);
        }
    }
    cout<<ans;
}
