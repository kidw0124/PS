#include<cstdio>
int main(){int N;scanf("%d",&N);int dp[46]={0,1};for(int i=2;i<=N;i++)dp[i]=dp[i-1]+dp[i-2];printf("%d",dp[N]);}