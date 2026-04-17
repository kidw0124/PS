#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL gcd(LL a,LL b){
    if(a<b)swap(a,b);
    if(!(a%b))return b;
    return gcd(b,a%b);
}

LL n,arr[110],a[110],pp[10000];

int main(){
    LL i,j,c=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(i=0;i<n-1;i++){
        a[i]=abs(arr[i+1]-arr[i]);
    }
    LL g=a[0];
    for(i=1;i<n-1;i++)g=gcd(g,a[i]);
    LL m=min(a[0],g);
    for(i=1;i*i<g&&i<m;i++){
        if(!(g%i)){
            pp[c++]=i;
            pp[c++]=g/i;
        }
    }
    if(i*i==g)pp[c++]=i;
    sort(pp,pp+c);
    for(i=1;i<c;i++){
        cout<<pp[i]<<' ';
    }
    return 0;
}
