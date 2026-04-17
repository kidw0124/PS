#include<bits/stdc++.h>
using namespace std;

int bin(int n,int r, int c){
    if(n==1)return ((r<<1)|c);
    int p=pow(2,n-1);
    int rr=r/p,cc=c/p;
    return ((rr<<1)|cc)*p*p+bin(n-1,r%p,c%p);
}

int main(){
    int i,j;
    int n,r,c;
    cin>>n>>r>>c;
    cout<<bin(n,r,c);
}
