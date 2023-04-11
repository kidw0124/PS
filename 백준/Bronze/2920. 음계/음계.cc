#include<stdio.h>

int main(){
    int i;
    int arr[8];
    int asc[8]={1,2,3,4,5,6,7,8};
    int des[8]={8,7,6,5,4,3,2,1};
    for(i=0;i<8;i++){
        scanf("%d",&arr[i]);
    }
    int flag = 0;
    for(i=0;i<8;i++){
        if(arr[i]!=asc[i]){
            flag = 1;
            break;
        }
    }
    if(flag==0){
        printf("ascending");
        return 0;
    }
    flag = 0;
    for(i=0;i<8;i++){
        if(arr[i]!=des[i]){
            flag = 1;
            break;
        }
    }
    if(flag==0){
        printf("descending");
        return 0;
    }
    printf("mixed");
}