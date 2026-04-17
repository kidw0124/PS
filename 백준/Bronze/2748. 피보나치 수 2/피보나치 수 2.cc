#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long long fibo[100];

long long fibonacci(int n){
    if(n<=1)return n;
    if(fibo[n]!=0)return fibo[n];
    return fibo[n]=fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    int i,j;
    int n;
    scanf("%d",&n);
    printf("%lld",fibonacci(n));
    return 0;
}
