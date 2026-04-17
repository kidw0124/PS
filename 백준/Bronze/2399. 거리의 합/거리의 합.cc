#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,ans=0;
    cin>>n;
    vector<int>arr(n);
    for(auto&k:arr)cin>>k;
    for(auto &k:arr)for(auto&k2:arr)ans+=abs(k-k2);
    cout<<ans<<'\n';
}