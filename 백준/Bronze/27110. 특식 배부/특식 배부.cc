#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,n;
    cin>>n>>a>>b>>c;
    cout<<min(n,a)+min(n,b)+min(n,c);
}