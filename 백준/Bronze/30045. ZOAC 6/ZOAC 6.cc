#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string>arr(n);
    for(auto&k:arr)cin>>k;
    cout<<count_if(arr.begin(),arr.end(),[](string&str){
        return (str.find("01")+1)||(str.find("OI")+1);
    });
}