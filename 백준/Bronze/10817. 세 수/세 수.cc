#include<bits/stdc++.h>

int main(){
    int arr[3];
    for(int i=0;i<3;i++){
        scanf("%d",arr+i);
    }
    std::sort(arr,arr+3);
    printf("%d",arr[1]);
}