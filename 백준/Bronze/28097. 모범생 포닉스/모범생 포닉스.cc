#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans=8*(n-1);
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        ans+=k;
    }
    cout<<ans/24<<' '<<ans%24;
}