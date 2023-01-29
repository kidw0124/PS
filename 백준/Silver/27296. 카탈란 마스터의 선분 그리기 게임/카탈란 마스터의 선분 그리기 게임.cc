#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        short n;
        cin>>n;//오버플로우시 SHORT_MAX여서 같음
        if(n<=1) cout<<"1 0\n";
        else cout<<"0 1\n";
    }
    return 0;
}