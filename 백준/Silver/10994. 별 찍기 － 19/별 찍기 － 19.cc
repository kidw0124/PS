#include<stdio.h>
#include<stdlib.h>
#include<math.h>

char arr[400][400];

void star(int n, int x, int y){
    int i;
//    if(n==0)return;
//    if(n==1){
//        arr[x][y]='*';
//        return;
//    }
    for(i=0;i<4*n-3;i++){
        arr[0+x][i+y]='*';
        arr[4*n-4+x][i+y]='*';
        arr[i+x][0+y]='*';
        arr[i+x][4*n-4+y]='*';
    }
    if(n>1)star(n-1,x+2,y+2);
}

void print(int n){
    int i,j;
    for(i=0;i<4*n-3;i++){
        j=4*n-4;
        while(arr[i][j]==' '){
            j--;
        }
        int c=j;
        for(j=0;j<=c;j++){
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int i,j;
    int n;
//    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(i=0;i<4*n-4;i++){
        for(j=0;j<4*n-4;j++){
            arr[i][j]=' ';
        }
    }
    star(n,0,0);
    print(n);
    return 0;
}
