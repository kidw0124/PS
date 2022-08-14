#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n),brr(n);
    for(int&k:arr)cin>>k;
    for(int&k:brr)cin>>k;
    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end(),greater<>());
    int x=0;
    for(int i=0;i<n;i++)x+=arr[i]*brr[i];
    cout<<x;
}