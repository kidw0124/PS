
#include<bits/stdc++.h>
using namespace std;
 
int n,X,s[1001][1001],dist[1001][3];
 
bool check[1001][2];
 
const int INF=9999999;
 
int sp(int st){
    int i,j;
    for(i=0;i<=n;i++){
        dist[i][0]=INF;
        dist[i][1]=INF;
    }
    dist[st][0]=0;
    dist[st][1]=0;
    for(i=1;i<=n;i++){
        int mn,md=INF;
        for(j=1;j<=n;j++){
            if(!check[j][0]&&md>dist[j][0]){
                mn=j,md=dist[j][0];
            }
        }
        check[mn][0]=1;
        for(j=1;j<=n;j++){
            if(dist[j][0]>md+s[mn][j]){
                dist[j][0]=md+s[mn][j];
            }
        }
    }
 
    for(i=1;i<=n;i++){
        int mn,md=INF;
        for(j=1;j<=n;j++){
            if(!check[j][1]&&md>dist[j][1]){
                mn=j,md=dist[j][1];
            }
        }
        check[mn][1]=1;
        for(j=1;j<=n;j++){
            if(dist[j][1]>md+s[j][mn]){
                dist[j][1]=md+s[j][mn];
            }
        }
    }
    int mini=0;
    for(i=1;i<=n;i++){
        if(mini<dist[i][0]+dist[i][1])mini=dist[i][0]+dist[i][1];
    }
 
    return printf("%d",mini);
}
 
int main() {
    int m;
    scanf("%d %d %d",&n,&m,&X);
    int i,j,x,y,t;
 
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            s[i][j]=INF;
        }
    }
    for(i=1; i<=m; i++) {
        scanf("%d %d",&x,&y);
        scanf("%d",&t);
        if(t<s[x][y]){
            s[x][y]=t;
        }
    }
    return 0*sp(X);
}