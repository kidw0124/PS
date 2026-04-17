#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<string>arr(n);
    for(auto &x:arr)cin>>x;
    cout<<count_if(arr.begin(),arr.end(),[](string str){return str[0]=='C';});
}