#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,sum=0;
    vector<int>arr(1050);
    for(i=0;i<10;i++){
        int t;
        cin>>t;
        sum+=t;
        arr[t]++;
    }
    cout<<sum/10<<'\n';
    cout<<max_element(arr.begin(),arr.end())-arr.begin();
}