#include<stdio.h>

int main(){
    int i;
    int arr[9];
    for(i=0;i<9;i++){
        scanf("%d",&arr[i]);
    }
    int ans=arr[0],idx=1;
    for(i=1;i<9;i++){
        if(ans<arr[i]){
            ans=arr[i];
            idx=i+1;
        }
    }
    printf("%d %d",ans,idx);
}