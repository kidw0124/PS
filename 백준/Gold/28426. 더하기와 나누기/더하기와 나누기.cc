#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,i,j;
    cin>>n;
    if(n==2){
        cout<<"3 6";
        return 0;
    }
    cout<<"2 ";
    if(n==1)return 0;
    for(i=1;i<n-1;i++){
        cout<<2*(i+1)<<' ';
    }
    if(n%2==0)i=n-1;
    else i=n;
    cout<<i;
}