#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    int ans=0,d=arr[0];
    arr.push_back(INT_MAX);
    for(int i=0;i<n;i++){
        if(arr[i]!=arr[i+1]-1){
            ans+=d;
            d=arr[i+1];
        }
    }
    cout<<ans;
}