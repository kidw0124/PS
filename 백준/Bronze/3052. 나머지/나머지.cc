#include<stdio.h>

int main(){
    int i;
    int arr[42]={};
    for(i=0;i<10;i++){
        int a;
        scanf("%d",&a);
        arr[a%42]++;
    }
    int cnt=0;
    for(i=0;i<42;i++){
        if(arr[i]!=0) cnt++;
    }
    printf("%d",cnt);
}