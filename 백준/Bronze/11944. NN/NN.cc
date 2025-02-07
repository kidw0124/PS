#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int m;
    cin>>n>>m;
    string ans;
    for(int i=0;i<n;i++){
        ans+=to_string(n);
    }
    cout<<ans.substr(0,m);
}