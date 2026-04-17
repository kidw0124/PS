#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1,s2;
int dp[1001][1001]={0};
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>s1>>s2;
    int l1=s1.size(),l2=s2.size();
    int i,j;
    for(i=1;i<=l1;i++){
        for(j=1;j<=l2;j++){
            dp[i][j]=(s1[i-1]-s2[j-1])?max(dp[i-1][j],dp[i][j-1]):dp[i-1][j-1]+1;
        }
    }
    cout<<dp[l1][l2];
}
