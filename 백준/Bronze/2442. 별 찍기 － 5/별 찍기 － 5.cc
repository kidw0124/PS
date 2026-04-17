#include<bits/stdc++.h>
using namespace std;

int main(){
    int i,j,m;
    scanf("%d",&m);
    for(i=0;i<m;i++){
        for(j=1;j<m-i;j++)
            printf(" ");
        for(j=0;j<2*i+1;j++)
            printf("*");
        puts("");
    }
}