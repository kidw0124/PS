#include<bits/stdc++.h>
using namespace std;
 
int t,k,cnt;
 
int dp[110][11000];
 
struct data{
    int pi,ni;
    bool operator<(const data&r)const{
        return pi<r.pi;
    }
}coin[110];
 
int main(){
    scanf("%d %d",&t,&k);
    int i,j,l;
    for(i=1;i<=k;i++){
        scanf("%d %d",&coin[i].pi,&coin[i].ni);
    }
    sort(coin+1,coin+1+k);
    dp[0][0]=1;
    for(i=1;i<=k;i++){
        for(j=0;j<=coin[i].ni;j++){
            for(l=0;l+coin[i].pi*j<=t;l++){
                dp[i][l+coin[i].pi*j]+=dp[i-1][l];
            }
        }
    }
    printf("%d",dp[k][t]);
}