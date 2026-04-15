#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    cout<<min((n+a-1)/a*b,(n+c-1)/c*d);}