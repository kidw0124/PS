#include<bits/stdc++.h>
using namespace std;
using ld=long double;
int main(){
    ld n;
    while(cin>>n,n){
        cout<<fixed<<setprecision(2)<<(n==1?((ld)5.00):(pow(n,5)-1)/(n-1))<<' ';
    }
    
    
    
}