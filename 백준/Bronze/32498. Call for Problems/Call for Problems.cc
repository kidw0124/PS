#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr)cin>>x;
    cout<<count_if(arr.begin(),arr.end(),[](int x){return x&1;});
}