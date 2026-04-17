#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto&k:arr)cin>>k;
    if(n%2==0&&ranges::min(arr)<ranges::max(arr))cout<<"Alice";
    else cout<<"Bob";
}