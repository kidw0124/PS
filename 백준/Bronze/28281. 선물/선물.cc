#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,m=1e9;
    cin>>n>>a;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i)m=min(arr[i-1]+arr[i],m);
    }
    cout<<m*a;
}