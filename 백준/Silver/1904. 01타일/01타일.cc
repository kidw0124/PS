#import<iostream>
main(){int N,a[1000000]={1,1},i=1;for(std::cin>>N;i++<=N;)a[i]=(a[i-1]+a[i-2])%15746;std::cout<<a[N];}