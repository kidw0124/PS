#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int>arr(10);
        for(auto&k:arr)cin>>k;
        sort(arr.begin(),arr.end(),greater<>());
        cout<<arr[2]<<' ';
    }
}