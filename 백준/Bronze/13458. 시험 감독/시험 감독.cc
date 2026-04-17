#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    vector<long long>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long b,c;
    cin>>b>>c;
    long long ans=n;
    for(int i=0;i<n;i++){
        ans+=max(0ll,(arr[i]-b+c-1)/c);
    }
    cout<<ans;
}