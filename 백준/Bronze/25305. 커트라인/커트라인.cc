#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(auto&k:arr)cin>>k;
    sort(arr.begin(),arr.end(),greater<>());
    cout<<arr[k-1];
}