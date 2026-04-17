#include<bits/stdc++.h>
using namespace std;
int main(){
    set<string>sst;
    sst.insert("keys");
    sst.insert("phone");
    sst.insert("wallet");
    int n;
    cin>>n;
    while(n--){
        string str;
        cin>>str;
        sst.erase(str);
    }
    for(auto&k:sst)cout<<k<<'\n';
    if(sst.empty())cout<<"ready";
}