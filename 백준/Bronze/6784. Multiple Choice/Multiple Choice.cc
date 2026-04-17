#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<char>a(n);
    char b;
    for(auto&x:a)cin>>x;
    for(auto&x:a)cin>>b,x^=b;
    cout<<ranges::count(a,0);
}