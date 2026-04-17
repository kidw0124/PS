#import<iostream>
main(){long long N,T,a[1000000]={0,1,1,1,2,2},i=5;for(std::cin>>T;i++<=100;)a[i]=(a[i-1]+a[i-5]);while(T--){std::cin>>N;std::cout<<a[N]<<'\n';}}