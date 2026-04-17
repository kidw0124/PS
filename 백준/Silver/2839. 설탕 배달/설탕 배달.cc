#include<iostream>

int main(){
    char i=0;
    short n;
    std::cin>>n;
    if(n==1||n==2||n==4||n==7)std::cout<<"-1";
    else{
        while(n%5){
            n-=3,i++;
        }
        std::cout<<n/5+i;
    }
    return 0;
}
