#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr)cin>>x;
    int sum=0,m;
    cin>>m;
    while(m--){
        cin>>n;
        sum+=arr[n-1];
    }
    cout<<sum;
    
}