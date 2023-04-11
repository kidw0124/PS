#include<stdio.h>

int main(){
    int i,j;
    int arr[105][105],brr[105][105];
    int n,m;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&brr[i][j]);
        }
    }
    int crr[105][105];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            crr[i][j]=arr[i][j]+brr[i][j];
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ",crr[i][j]);
        }
    }
}