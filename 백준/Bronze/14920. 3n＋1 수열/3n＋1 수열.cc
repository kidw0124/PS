#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,n=1;
    cin>>a;
    while(a!=1){
        if(a&1)a=3*a+1;
        else a/=2;
        n++;
        }cout<<n;}