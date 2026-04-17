#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a=0,i,j;
    cin>>n>>m;
    for(i=0;i<n;i++){for(j=0;j<m;j++){cout<<++a;if(j!=m-1)cout<<' ';}cout<<'\n';}
}