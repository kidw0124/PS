#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,n,m,a,b;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<m;i++)cin>>a>>b;
        cout<<n-1<<'\n';
    }
}