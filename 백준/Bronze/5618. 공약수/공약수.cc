#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int g=0,i,j;
    for(i=0;i<n;i++){
        cin>>j;
        g=gcd(g,j);
    }
    for(i=1;i<=g;i++)if(g%i==0)cout<<i<<'\n';
}