#import<iostream>
#import<cstdio>
int main(){
    int t,M=0,b[99],a[46]={0,1},i=-1;
    for(std::cin>>t;++i<t;){
        std::cin>>b[i];
        if(M<b[i])M=b[i];
    }
    for(i=1;i++<=M;)a[i]=a[i-1]+a[i-2];
    for(i=0;i<t;i++){
        if(!b[i])puts("1 0");
        else printf("%d %d\n",a[b[i]-1],a[b[i]]);
    }
}