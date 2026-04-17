#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b;
    cin>>n>>a>>b;
    if(b<a)cout<<"Subway";
    else if(b==a)cout<<"Anything";
    else cout<<"Bus";
}