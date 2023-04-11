#include<stdio.h>

int main(){
    int i,j;
    int arr[9][9];
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int max=arr[0][0],x=0,y=0;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(arr[i][j]>max){
                max=arr[i][j];
                x=i;
                y=j;
            }
        }
    }
    printf("%d %d %d",max,x+1,y+1);
}