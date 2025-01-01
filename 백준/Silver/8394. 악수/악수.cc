#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n+1);
    arr[1]=1,arr[2]=2;
    for(int i=3;i<=n;i++){
        arr[i]=(arr[i-1]+arr[i-2])%10;
    }
    cout<<arr[n];
}