#include <bits/stdc++.h>
using namespace std;
#define INF 10000001
int d[101][10001];
int m[101], cost[101], n, memory;\
int main(){
 
    int i, j, sum=0, res=INF;
    scanf("%d %d", &n, &memory);
 
    for(i=1;i<=n;i++) {
        scanf("%d", &m[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%d", &cost[i]);
        sum+=cost[i];
    }
    for(i=1;i<=n;i++){
        for(j=0;j<=sum;j++){
            int a=j-cost[i];
            d[i][j]=d[i][j-1];
            if(a>=0) d[i][j]=max(d[i-1][a]+m[i], d[i][j]);
            if(i>0) d[i][j]=max(d[i][j], d[i-1][j]);
            if(d[i][j]>=memory && res>=j) res=j;
        }
    }
    printf("%d", res);
    return 0;
}