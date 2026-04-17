#include<cstdio>
char day[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int x,y;

int main(){
    int i,d=0;
    scanf("%d %d",&x,&y);
    for(i=0;i<x-1;i++)d+=m[i];
    d+=y-1;
    printf("%s",day[d%7]);
}