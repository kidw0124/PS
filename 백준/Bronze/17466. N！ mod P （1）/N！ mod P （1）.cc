#include<bits/stdc++.h>
#pragma warning(disable:4996)
long long n,a=1,p;
int main(){
    long long i,j;
    std::cin>>n>>p;
    for(i=2;i<=n;i++){a*=i;a%=p;}
    std::cout<<a;
    return 0;
}
