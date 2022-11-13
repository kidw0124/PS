#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n;
        cin>>n;
        cout<<"Case "<<i<<": "<<n-1<<" ";
        while(n--){
            int x;
            cin>>x;
            cout<<x*(n+1)<<' ';
        }
        cin>>n;
        cout<<'\n';
    }
}