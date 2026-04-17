#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    int n=str.size(),ans=0;
    for(int i=0;i<=n-4;i++){
        if(str.substr(i,4)=="kick"){
            ans++;
        }
    }
    cout<<ans;
}