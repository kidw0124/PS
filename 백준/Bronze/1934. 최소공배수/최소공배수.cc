#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL x,y;
LL gcd(LL a,LL b){
    if(a<b)swap(a,b);
    if(!(a%b))return b;
    return gcd(b,a%b);
}

LL lcm(LL a, LL b){
    return a*b/gcd(a,b);
}

int main(){
    int t,i;   
    cin>>t;
    for(i=0;i<t;i++){
    cin>>x>>y;
    cout<<lcm(x,y)<<endl;
    }
    return 0;
}