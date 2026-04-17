#include<bits/stdc++.h>
using namespace std;

vector<int>arr;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<2*n;i++){
        int t;
        cin>>t;
        arr.push_back(t);
    }
    sort(arr.begin(),arr.end());
    int m=9999999;
    for(int i=0;i<n;i++){
        m=min(m,arr[i]+arr[2*n-i-1]);
    }
    cout<<m;
}
