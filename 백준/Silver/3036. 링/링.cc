#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL gcd(LL a,LL b){
    if(a<b)swap(a,b);
    if(!(a%b))return b;
    return gcd(b,a%b);
}


int main(){
    int i,j;
    LL N,d;
    cin>>N>>d;
    for(i=1;i<N;i++){
        LL t;
        cin>>t;
        LL g=gcd(d,t);
        cout<<d/g<<"/"<<t/g<<endl;
    }


    return 0;
}
