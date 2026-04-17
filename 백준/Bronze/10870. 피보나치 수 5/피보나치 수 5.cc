#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int fibonacci(int n){
    if(n<=1)return n;
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    int i,j;
    int n;
    scanf("%d",&n);
    printf("%d",fibonacci(n));
    return 0;
}
