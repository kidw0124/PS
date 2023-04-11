#include<stdio.h>

int main(){
    int i;
    int arr[105];
    int n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%1d",&arr[i]);
    }
    int ans=0;
    for(i=0;i<n;i++){
        ans+=arr[i];
    }
    printf("%d",ans);
}