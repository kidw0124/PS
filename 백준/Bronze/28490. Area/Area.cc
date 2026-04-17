#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;int ans=0,w,h;
    while(n--){cin>>w>>h;ans=max(ans,w*h);}
    cout<<ans;}