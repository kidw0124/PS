#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    long long ans=0;
    cin>>a>>b;
    for(auto k:a){
        for(auto kk:b){
            ans+=(k-'0')*(kk-'0');
        }
    }
    cout<<ans;
}