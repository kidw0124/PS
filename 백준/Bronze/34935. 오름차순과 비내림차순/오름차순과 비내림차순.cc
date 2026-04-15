#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector arr(n,0ll);
    for(auto&x:arr)cin>>x;
    cout<<(unique(arr.begin(),arr.end())==arr.end());
}