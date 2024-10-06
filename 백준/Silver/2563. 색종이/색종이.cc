#include<stdio.h>

int main(){
    int i,j;
    int arr[105][105]={};
    int n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        for(j=x;j<x+10;j++){
            for(int k=y;k<y+10;k++){
                arr[j][k]=1;
            }
        }
    }
    int cnt=0;
    for(i=0;i<105;i++){
        for(j=0;j<105;j++){
            if(arr[i][j]==1){
                cnt++;
            }
        }
    }
    printf("%d",cnt);
}