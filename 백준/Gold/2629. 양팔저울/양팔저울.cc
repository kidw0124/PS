#include<cstdio>
using namespace std;
 
bool dp[32][80010];
 
int w[32],g[10],wsum;
 
int main(){
    int n,c;
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++){
        scanf("%d",w+i);
        wsum+=w[i];
    }
    scanf("%d",&c);
    for(i=0;i<c;i++){
        scanf("%d",g+i);
    }
    dp[0][30000]=true;
    for(i=0;i<n;i++){
        for(j=0;j<=wsum+30000;j++){
            if(dp[i][j]==true){
                dp[i+1][j]=true;
                dp[i+1][j-w[i]]=true;
                dp[i+1][w[i]+j]=true;
            }
        }
    }
    for(i=0;i<c;i++){
        printf("%c ",dp[n][g[i]+30000]?'Y':'N');
    }
}