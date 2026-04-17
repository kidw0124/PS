#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j;
    cin>>n;
    n++;
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            cout<<"*";
        }
        for(j=0;j<2*n-2-2*i;j++){
            cout<<" ";
        }
        for(j=0;j<i;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
    for(i=n-2;i>=1;i--){
        for(j=0;j<i;j++){
            cout<<"*";
        }
        for(j=0;j<2*n-2-2*i;j++){
            cout<<" ";
        }
        for(j=0;j<i;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
}