#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr(3);
    for(auto&k:arr)cin>>k;
    ranges::sort(arr);
    if(arr[0]==arr[2])cout<<2;
    else if(arr[0]*arr[0]+arr[1]*arr[1]==arr[2]*arr[2])cout<<1;
    else cout<<0;
}